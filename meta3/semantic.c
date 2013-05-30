#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "structures.h"
#include "shows.h"
#include "symbol_table.h"
#include "semantic.h"

enum{GLOBALSCOPE, LOCALSCOPE};

int global_offset=0;

prog_env* semantic_analysis(is_node* myProgram) 
{
	is_node *aux;

	prog_env* pe=(prog_env*)malloc(sizeof(prog_env));		

	for(aux=myProgram; aux; aux=aux->next)	
	{
		semantic_analysis_block(pe, aux);
	}
	
	return pe;
}


void semantic_analysis_block(prog_env *pe, is_node* ip)
{	
	//faz a triagem do bloco a analisar
 	//show_expression(ip, 0);
 	switch(ip->d_node)
	{
	//case d_declaration: semantic_analysis_procedure(pe, ip->data_block.u_procedure);  break;
	case d_declaration: semantic_analysis_globals(pe, ip); break;
	case d_func_definition: semantic_analysis_procedures(pe, ip); break;
	case d_func_declaration: semantic_analysis_procedures(pe, ip); break;
	default: break;
	}
		
}

void semantic_analysis_globals(prog_env *pe, is_node* ipg){ //Recebe o declaration

	pe->global=semantic_analysis_vardeclist(GLOBALSCOPE, pe, pe->global, ipg->child);	

}

table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_node* ivl) //Recebe char
{
	is_node* aux;
	int offset=0;
	table_element* stmp=stable;

	for(aux=ivl->next; aux; aux=aux->next) //Corre lista de declaration->child's a partir do char para a frente

		switch(aux->d_node){

		case d_null: break;
		default:
			stmp=semantic_analysis_vardec((scope==LOCALSCOPE?offset++:global_offset++), pe, stmp, aux, ivl->d_node);
			break;
		}
	return stmp;
}

table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_node* iv, disc_node type)
{
	table_element *aux, *last, *stmp=stable;
	is_node *stringAux;

	for(stringAux=iv->child; stringAux->d_node != d_id; stringAux=stringAux->next); 
	aux=lookup(pe->global, stringAux->data.string); 	//verifica na tabela global

	if(aux!=0 && aux->type==d_func_definition)		//se existir e for um procedimento, temos um erro!
	{
		printf("Error: Cannot define %s, already defined as procedure!\n", iv->child->data.string);
		return stmp;
	}

	//procura por uma vari‡vel com o mesmo nome
	for(aux=last=stmp; aux; last=aux, aux=aux->next){
		if(strcmp(stringAux->data.string, aux->name)==0){
			return stmp;
		}
	}
	if(last==NULL){	//se n‹o existe e a tabela est‡ vazia
		stmp=create_symbol(offset, iv->child, type);	//criar um símbolo na cabeça da lista de símbolos, stable
	}
	else{
		if(strcmp(stringAux->data.string, last->name)!=0){		//se n‹o existe 
			last->next=create_symbol(offset, iv->child, type);//coloca no final da stable
		}
		else{				//EXISTE! J‡ est‡ definida!!!
			//printf("Error: %s already defined!\n", stringAux->data.string);
		}
	}
	return stmp;
}

table_element *lookup(table_element* table, char *str)
{
table_element *aux;

for(aux=table; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return 0;
}

table_element* create_symbol(int offset, is_node* node, disc_node type)
{

	table_element* el=(table_element*)malloc(sizeof(table_element));
	is_node *aux;
	el->type_data.pointers = 0;
	el->type_data.size = -1;

	switch(type){
		case d_char: el->type_data.type = CHARe; break;
		case d_int: el->type_data.type = INTe; break;
		case d_func_definition: el->type_data.type = FUNC; break;
		default: break;
	}

	for(aux=node; aux; aux=aux->next){
		switch(aux->d_node){
			case d_id: strcpy(el->name, aux->data.string); break;
			case d_intlit: el->type_data.size = aux->data.number;break;
			case d_pointer: el->type_data.pointers += 1; break;
			default: break;
		}
	}

	/*strcpy(el->name,name);
	el->type=type;*/
	el->next=NULL;
	el->offset=offset;
	return el;
}

void semantic_analysis_procedures(prog_env *pe, is_node* ipg){
	environment_list* aux;
	table_element *te;
	is_node *stringAux, *stringAux2; //StringAux -> funcdefinition; StringAux2 -> funcdeclarator
	environment_list* p1; 
	disc_node aux_return;
	int nPointers=0;
	int offset=0;

	for(stringAux=ipg->child; stringAux->d_node != d_func_declarator; stringAux=stringAux->next){
		if(stringAux->d_node != d_null ){
			aux_return = stringAux->d_node; // Guarda o retorno
		}
	}

	for(stringAux2 = stringAux->child; stringAux2->d_node != d_id; stringAux2=stringAux2->next){ // procura o nome da funcao
		if(stringAux2->d_node == d_pointer){
			nPointers++;
		}

	}

	if(lookup(pe->global, stringAux2->data.string)){

		for(p1=pe->procs; strcmp(p1->name, stringAux2->data.string); p1=p1->next);
		for(; stringAux !=NULL && stringAux->d_node != d_func_body ; stringAux=stringAux->next);
		if(stringAux != NULL && stringAux->d_node == d_func_body){
			for(stringAux=stringAux->child; stringAux; stringAux=stringAux->next){

				if(stringAux->d_node == d_declaration){
					//Envia declaration para ser analisado
					p1->locals = semantic_analysis_create_locals(offset++, stringAux->child, p1->locals, p1);
				
				}

			}
		}

	

	} else {

		p1 = (environment_list*) malloc (sizeof(environment_list));

		te=pe->global;

		if(te==NULL){
			pe->global = create_symbol(-1, stringAux2, d_func_definition);
			pe->global->type = d_func_definition;
		} else {
			for(; te->next; te=te->next);
			te->next = create_symbol(-1, stringAux2, d_func_definition);
			te->next->type = d_func_definition;
		}

		p1->name = (char*)strdup(stringAux2->data.string);
		p1->locals = (table_element*) malloc (sizeof(table_element));
		p1->return_type = aux_return;
		p1->pointers = nPointers;

		for(; stringAux2; stringAux2=stringAux2->next){
			if(stringAux2->d_node == d_param_declaration){ 
				//Chama funcao de analise de parametros de entrada
				p1->params=semantic_analysis_create_param_data(pe, stringAux2, p1->params);
			}
		}

		p1->locals = NULL;
		for(; stringAux !=NULL && stringAux->d_node != d_func_body ; stringAux=stringAux->next);

		if(stringAux != NULL && stringAux->d_node == d_func_body){
			for(stringAux=stringAux->child; stringAux; stringAux=stringAux->next){

				if(stringAux->d_node == d_declaration){
					//Envia declaration para ser analisado
					p1->locals = semantic_analysis_create_locals(offset++, stringAux->child, p1->locals, p1);
				
				}

			}
		}
		if(pe->procs == NULL){
			pe->procs = p1;
		} else {
			for(aux=pe->procs; aux->next!=NULL; aux=aux->next);
			aux->next = p1;
		}
	}

}

param_data* semantic_analysis_create_param_data(prog_env* pe, is_node* pi, param_data* params){

	table_element *aux;
	is_node *stringAux;
	param_data* paramAux;


	for(stringAux=pi->child; stringAux->d_node!=d_id; stringAux=stringAux->next);
	//Nao Verifica se ja existem na tabela de globais
	

		paramAux = params;

		if(paramAux == NULL){
			params = create_param(pi->child);
		} else {
			for(; paramAux->next!=NULL; paramAux=paramAux->next);
			paramAux->next = create_param(pi->child);
		}



	return params;
}

param_data* create_param(is_node* pip){

	param_data *el = (param_data*) malloc (sizeof(param_data));
	is_node *aux;
	el->pointers = 0;

	for(aux=pip; aux; aux=aux->next){

		switch(aux->d_node){
			case d_char: el->type = CHARe; break;
			case d_int: el->type = INTe; break;
			case d_id: el->name=(char*)strdup(aux->data.string); break;
			case d_pointer: el->pointers+=1; break;
			default: break;
		}

	}

	el->next = NULL;
 	
 	return el;
}

table_element* semantic_analysis_create_locals(int offset, is_node* ip, table_element* locals, environment_list* ev){

	is_node * stringAux2;
	disc_node type;
	table_element* localsAux;



	for(stringAux2=ip; stringAux2->d_node == d_null; stringAux2=stringAux2->next);
	type = stringAux2->d_node;

	for(stringAux2=ip; stringAux2; stringAux2=stringAux2->next){
		if(stringAux2->d_node == d_declarator || stringAux2->d_node == d_array_declarator){
			localsAux=locals;
			if(localsAux==NULL){
				locals = create_symbol(offset, stringAux2->child, type);
			} else {
				for(localsAux=locals; localsAux->next!=NULL; localsAux=localsAux->next){
				}
				localsAux->next = create_symbol(offset, stringAux2->child, type);
			}

		}

	}

	return locals;

}

environment_list *lookup_proc(environment_list* ev, char *str)
{
environment_list *aux;

for(aux=ev; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return 0;
}








