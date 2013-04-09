#include "structures.h"
#include "symbol_table.h"
#include "semantic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum {LOCALSCOPE, GLOBALSCOPE};

int global_offset=0;
int maincount;

prog_env* semantic_analysis(is_block_list* ipl) //an‡lise sem‰ntica da lista de blocos, ou seja do nosso programa
{
	is_block_list *aux;

	prog_env* pe=(prog_env*)malloc(sizeof(prog_env));		//criação do program_environment, que conter‡ todas os símbolos (globais, locais, procedimentos)

	//vamos fazer an‡lise sem‰ntica bloco a bloco
	for(aux=ipl; aux; aux=aux->next)	
	{	
		//Note-se que se envia o program environment existente. Para o bloco poder verificar, por exemplo, se um dado procedimento existe, ou uma vari‡vel global
		semantic_analysis_block(pe, aux->p,ipl);
	}
	
	return pe;
}

void semantic_analysis_block(prog_env *pe, is_block* ip,is_block_list *ibl)
{
	//faz a triagem do bloco a analisar
	switch(ip->disc_d)
	{
	case d_procedure: semantic_analysis_procedure(pe, ip->data_block.u_procedure,ibl);  break;
	case d_globals: semantic_analysis_globals(pe, ip->data_block.u_globals);break;
	}
		
}

void semantic_analysis_procedure(prog_env *pe, is_procedure* ipr,is_block_list *ibl)
{
	environment_list *aux;
	table_element *te;	
	
	environment_list *pl;

	if(lookup(pe->global, ipr->name))
	{
		printf("Symbol %s already defined! Cannot create procedure!\n", ipr->name);
		erros++;
		
	}
	else
		{
		pl=(environment_list*)malloc(sizeof(environment_list)); //cria um nodo para a lista de ambientes 
																//(que Ž mantida no program environment)
		
		te=pe->global; //Vai buscar tabela de simbolos globais


		//adiciona entrada para procedimento
		//na tabela de simbolos global. offset = -1 =>procedimento.
		//Serve apenas para facilitar na pesquisa (na realidade, Ž uma redundncia, pois
		//haver‡ tambŽm uma entrada na lista de ambientes)
		if(te==NULL)
			pe->global=create_symbol(-1, ipr->name, procedure,-1);
		else
			{
			for(; te->next; te=te->next);					
			te->next=create_symbol(-1, ipr->name, procedure,-1);		
			}
		
		//preenche entrada para o procedimento na lista de ambientes
		pl->name=(char*)strdup(ipr->name);	
		pl->locals=(table_element*)malloc(sizeof(table_element));
		//faz an‡lise sem‰ntica do procedimento
		// Ž aqui que vai adicionando os s’mbolos encontrados dentro do procedimento ao ambiente (representado por pl->locals)
		semantic_analysis_argvardeclist(LOCALSCOPE, pe, pl->locals,ipr->avlist);//indica args;
		semantic_analysis_vardeclist(LOCALSCOPE, pe, pl->locals, ipr->vlist);//indica var local;	
		semantic_analysis_statement_list(pe, pl->locals, ipr->slist,ipr->name,ibl);
		
		}

	//Adiciona ao program environment
	if(pe->procs==NULL)	//Caso seja o primeiro procedimento, fica na cabea
		pe->procs=pl;
	else			//sen‹o, fica na cauda
		{
		for(aux=pe->procs; aux->next; aux=aux->next);
			aux->next=pl;
		}
}

//An‡lise das declara›es de vari‡veis globais
void semantic_analysis_globals(prog_env *pe, is_globals* ipg)
{
	pe->global=semantic_analysis_vardeclist(GLOBALSCOPE, pe, pe->global, ipg->vlist);	//0 -> global
}

table_element *semantic_analysis_argvardeclist(int scope, prog_env *pe, table_element* stable, is_args_vardec_list* iavl){

	is_args_vardec_list* aux;
	int offset=0;
	table_element* stmp=stable;

	for(aux=iavl; aux; aux=aux->next){
		stmp=semantic_analysis_argvardec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux->av);
	}
	return stmp;
}

//An‡lise de declara›es de vari‡veis
//Ž necess‡rio saber o scope para saber onde calcular o offset das vari‡veis nos registos de activa‹o
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_vardec_list* ivl)
{
	is_vardec_list* aux;
	int offset=0;
	table_element* stmp=stable;

	for(aux=ivl; aux; aux=aux->next)
		stmp=semantic_analysis_vardec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux->v);

	return stmp;
}

//Dependendo do scope, esta função verifica primeiro se j‡ existe a vari‡vel nas tabelas de símbolos. Não pode existir na tabela de símbolos "corrente". Apenas nas "superiores"
//Caso exista como vari‡vel ou até como procedimento (uma vari‡vel não pode nunca ser definida local, ou globalmente, se existir um procedimento com o seu nome), emite-se uma mensagem
//de erro
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_vardec* iv)
{
	table_element *aux, *last,*arg, *stmp=stable;

	aux=lookup(pe->global, iv->name); 	//verifica na tabela global
	

	if(aux!=0 && aux->type==procedure)		//se existir e for um procedimento, temos um erro!
		{
		printf("line %d: error: Cannot define %s, already defined as procedure!\n", iv->codeline, iv->name);
		erros++;
		return stmp;
	}


	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(iv->name, aux->name)==0)
			break;

	if(last==NULL)	//se n‹o existe e a tabela est‡ vazia
		stmp=create_symbol(offset, iv->name, iv->disc_d,1);	//criar um símbolo na cabeça da lista de símbolos, stable
	else{
		if(last->next==NULL)		//se n‹o existe 
			last->next=create_symbol(offset, iv->name, iv->disc_d,1);	//coloca no final da stable
		else				//EXISTE! J‡ est‡ definida!!!
		{
			printf("line %d: error: %s already defined!\n", iv->codeline, iv->name);
			erros++;
		}
	}
	return stmp;
}

table_element *semantic_analysis_argvardec(int offset, prog_env* pe, table_element* stable, is_args_vardec* iav){
	table_element *aux, *last, *stmp=stable;

	aux=lookup(pe->global, iav->name); 	//verifica na tabela global
	if(aux!=0 && aux->type==procedure)		//se existir e for um procedimento, temos um erro!
	{
		printf("line %d: error: Cannot define %s, already defined as procedure!\n", iav->codeline, iav->name);
		erros++;
		return stmp;
	}
	
	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next)
		if(strcmp(iav->name, aux->name)==0)
			break;
	
	if(last==NULL)	//se n‹o existe e a tabela est‡ vazia
		stmp=create_symbol(offset, iav->name, iav->type, 2);	//criar um símbolo na cabeça da lista de símbolos, stable
	else{
		if(last->next==NULL){		//se n‹o existe
			last->next=create_symbol(offset, iav->name, iav->type, 2);	//coloca no final da stable
		}
		else				//EXISTE! J‡ est‡ definida!!!
		{
			printf("line %d: error: %s already defined!\n", iav->codeline, iav->name);
			erros++;
		}
	return stmp;

	}

}


//An‡lise sem‰ntica de listas de statements
void semantic_analysis_statement_list(prog_env *pe, table_element* local, is_statement_list* isl,char *name,is_block_list *ibl)
{
	is_statement_list* aux;

	for(aux=isl; aux; aux=aux->next){
		semantic_analysis_statement(pe, local, aux->s,name,ibl);
	}

}

//Triagem por tipo de statement
void semantic_analysis_statement(prog_env *pe, table_element* local, is_statement* is,char *name,is_block_list *ibl)
{
	switch(is->disc_d)
	{
	case d_write_stat:	
		semantic_analysis_write_stat(pe, local, is->data_statement.u_write_stat);break;
				
	case d_assgn_stat:
		semantic_analysis_assgn_stat(pe, local, is->data_statement.u_assgn_stat);
		break;
	case d_call_stat: semantic_analysis_call_stat(pe,name,local ,is->data_statement.u_call_stat,ibl);break;
	}
}

//S— se faz um write se a vari‡vel existir e se n‹o for um procedimento
void semantic_analysis_write_stat(prog_env *pe, table_element* local, is_write_stat* iws)
{
	table_element	*e;
	

	e=lookup(pe->global, iws->var);
	if(e && e->type==procedure)
	{
		printf("line %d: %s is a procedure! It cannot be printed...\n", iws->codeline, iws->var);
		erros++;
	}
	else{
		if(!lookup(local, iws->var)&& !e  ){
			printf("line %d: Unknown variable: %s\n", iws->codeline, iws->var);
			erros++;
		}
	}

}

//S— se faz um assignment se a vari‡vel que receber o valor for do mesmo tipo que o valor
void semantic_analysis_assgn_stat(prog_env *pe, table_element* local, is_assgn_stat* ias){
	table_element *e=lookup(local, ias->var);

	if(!e)
		e=lookup(pe->global, ias->var);

	if(!e)
	{
		printf("line %d: Unknown variable: %s\n", ias->codeline, ias->var);
		erros++;
	}
	else{
		if(e->type==procedure)
		{
			printf("line %d: Cannot make assignment to a procedure: %s\n", ias->codeline, ias->var);
			erros++;
		}
		else
			if(e->type!=ias->disc_d && !(e->type==integer && ias->disc_d==input_int) && !(e->type==doub && ias->disc_d==input_double) && 
			!(e->type==character && ias->disc_d==input_char))
			{
				printf("line %d: Type mismatch! %s<>%s\n", ias->codeline, typeToString(e->type), typeToString(ias->disc_d));
				erros++;
			}
	}
}

//S— se faz um call se existir o procedimento com o nome dado
is_args_vardec_list* semantic_analysis_call_stat(prog_env *pe,char *nameProc,table_element *local, is_call_stat* ics,is_block_list *ibl)
{
	table_element *e=lookup(pe->global, ics->proc);
	if(!e || e->type!=procedure)
	{
		printf("line %d: Unknown procedure: %s\n", ics->codeline, ics->proc);
		erros++;
		return NULL;
	}
	is_block_list *l = ibl;
	is_args_vardec_list *iavl;
	is_statement_list *istl;
	while(l!=NULL){
		if(strcmp(l->p->data_block.u_procedure->name,ics->proc)==0){
			iavl = l->p->data_block.u_procedure->avlist;
			break;
		}
		l=l->next;
	}
	l = ibl;
	while(l!=NULL){
		if(strcmp(l->p->data_block.u_procedure->name,nameProc)==0){
			istl = l->p->data_block.u_procedure->slist;
			break;
		}
		l=l->next;
	}
	
	environment_list *p = plookup(pe->procs,ics->proc);
	is_call_arg_list *aux2 = ics->ical;
	e = p->locals;
	is_statement_list *s;
	s = istl;
	int conta=0,contaArg =0;
	while(aux2!=NULL){
		if(strcmp(aux2->ca->name , "")!=0){
			while(s!=NULL){
				if(strcmp(s->s->data_statement.u_assgn_stat->var,aux2->ca->name)==0){
					aux2->ca->type = s->s->data_statement.u_assgn_stat->disc_d;
					break;
				}
				s=s->next;
			}
		}
		conta++;
		aux2=aux2->next;
	}
	while(e!=NULL){
		if(e->isArg == 2)
			contaArg++;
		e = e->next;
	}
	if(conta<contaArg){
		printf("line %d: A few arguments in this call! %d in procedure and %d in call \n", ics->codeline,contaArg,conta);
		erros++;
		return NULL;
	}
	if(conta>contaArg){
		printf("line %d: too many arguments in this call! %d in procedure and %d in call \n", ics->codeline,contaArg,conta);
		erros++;
		return NULL;
	}
	aux2 = ics->ical;

	while(iavl!=NULL){
		e = p->locals;
		s=istl;
		if(iavl->av->type != aux2->ca->type ){
			printf("line %d: Type mismatch! %s<>%s\n", ics->codeline, typeToString(iavl->av->type), typeToString(aux2->ca->type));
			erros++;
			break;
		}
		if(strcmp(aux2->ca->name , "")!=0){
			while(s!=NULL){
				if(strcmp(s->s->data_statement.u_assgn_stat->var,aux2->ca->name)==0){
					switch(iavl->av->type){
						case integer:
						iavl->av->veri = 0;
						iavl->av->list = s->s->data_statement.u_assgn_stat->list;
						break;
						case doub:
						iavl->av->veri = 0;
						iavl->av->list = s->s->data_statement.u_assgn_stat->list;
						break;
						case character:
						iavl->av->veri = 1;
						iavl->av->data_args.c = aux2->ca->data_args.c;
						break;
						case bool:
						iavl->av->veri = 1;
						iavl->av->data_args.b = aux2->ca->data_args.b;
						break;
					}
					break;	
				}
				s=s->next;
			}
		}
		else{
			switch(iavl->av->type){
				case integer:
				iavl->av->veri = 1;
				iavl->av->data_args.i = aux2->ca->data_args.i;
				break;
				case doub:
				iavl->av->veri = 1;
				iavl->av->data_args.d = aux2->ca->data_args.d;
				break;
				case character:
				iavl->av->veri = 1;
				iavl->av->data_args.c = aux2->ca->data_args.c;
				break;
				case bool:
				iavl->av->veri = 1;
				iavl->av->data_args.b = aux2->ca->data_args.b;
				break;
			}
		}
		aux2=aux2->next;
		iavl=iavl->next;
	}
}


//Convers‹o enum-> string para ajudar no output de erros
char* typeToString(int type)
{
	switch(type)
	{
	case integer: return "integer";
	case character: return "char";
	case doub: return "double";
	case bool: return "boolean";
	case procedure: return "procedure";
	}
	erros++;
	return "unknown type";
}

//Criação de uma estrutura table_element
table_element* create_symbol(int offset, char* name, basic_type type,int isArg)
{
	table_element* el=(table_element*)malloc(sizeof(table_element));
	strcpy(el->name,name);
	el->isArg = isArg;
	el->type=type;
	el->next=NULL;
	el->offset=offset;
	return el;
}

//Procura um identificador, devolve 0 caso n‹o exista
table_element *lookup(table_element* table, char *str)
{
table_element *aux;

for(aux=table; aux; aux=aux->next){
	if(strcmp(aux->name, str)==0){
		return aux;
	}
}

return 0;
}

environment_list *plookup(environment_list* procs, char* procname)
{
	environment_list* aux;

	for(aux=procs; aux; aux=aux->next)
		if(strcmp(aux->name, procname)==0)
			return aux;

	return NULL;
}



