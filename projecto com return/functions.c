#include "structures.h"
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

is_assgn_stat* insert_assgn_stat_char(int line, char* var, char c)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=character;
	ias->data_assgn_stat.c=c;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	return ias;
}

is_return_statement* insert_return_stat(int line,char* name)
{
	is_return_statement* irs=(is_return_statement*)malloc(sizeof(is_return_statement));
	irs->codeline=line;
	irs->name=(char*)strdup(name);
}

is_assgn_stat* insert_assgn_stat_int(int line, char* var, is_expression_list* list)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=integer;
	ias->list=list;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	
	return ias;
}

is_assgn_stat* insert_assgn_stat_read_char(int line, char* var)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=input_char;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	
	return ias;
}

is_assgn_stat* insert_assgn_stat_read_int(int line, char* var)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=input_int;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	
	return ias;
}

is_assgn_stat* insert_assgn_stat_read_double(int line, char* var)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=input_double;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	
	return ias;
}


is_assgn_stat* insert_assgn_stat_double(int line, char* var, is_expression_list* list)
{
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=doub;
	ias->list=list;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	return ias;
}

is_assgn_stat* insert_assgn_stat_boolean(int line, char *var, boolean b){
	is_assgn_stat* ias=(is_assgn_stat*)malloc(sizeof(is_assgn_stat));
	ias->disc_d=bool;
	ias->data_assgn_stat.b=b;
	ias->var=(char*)strdup(var);
	ias->codeline=line;
	return ias;
}




is_block_list *insert_block_list(is_block_list* list, is_block *prog)
{
	is_block_list *ipl=(is_block_list*)malloc(sizeof(is_block_list));
	is_block_list *aux;
	ipl->p=prog;
	ipl->next=NULL;

	if(list)
		{
		for(aux=list; aux->next; aux=aux->next);
		aux->next=ipl;
		return list;
		}
	return ipl;
}

is_block* insert_procedure(char* name, is_args_vardec_list *alist,is_vardec_list* vlist, is_statement_list* slist)
{
	is_block* ip=(is_block*)malloc(sizeof(is_block));
	is_procedure* ipr=(is_procedure*)malloc(sizeof(is_procedure));
	ipr->name=(char*)strdup(name);
	ipr->vlist=vlist;
	ipr->slist=slist;
	ipr->avlist=alist;
	ip->disc_d=d_procedure;
	ip->data_block.u_procedure=ipr;
	return ip;
}

is_block* insert_globals(is_vardec_list* vlist)
{
	is_block* ip=(is_block*)malloc(sizeof(is_block));
	is_globals* ipg=(is_globals*)malloc(sizeof(is_globals));
	ipg->vlist=vlist;
	ip->disc_d=d_globals;
	ip->data_block.u_globals=ipg;
	return ip;
}

is_vardec_list *insert_vardec_list(is_vardec_list* list, is_vardec* v)
{
	is_vardec_list* ivl=(is_vardec_list*)malloc(sizeof(is_vardec_list));
	is_vardec_list* aux;
	ivl->v=v;
	ivl->next=NULL;

	if(list)
		{
		for(aux=list; aux->next; aux=aux->next);
		aux->next=ivl;
		return list;
		}

	return ivl;
}

is_vardec *insert_vardec(int line, basic_type type, char* name)
{
	is_vardec* iv=(is_vardec*)malloc(sizeof(is_vardec));
	iv->disc_d=type;
	iv->name=(char*)strdup(name);
	iv->codeline=line;
	return iv;
}

is_statement_list* insert_statement_list(is_statement_list *list, is_statement *statement)
{
	is_statement_list* isl=(is_statement_list*)malloc(sizeof(is_statement_list));
	is_statement_list* aux;
	isl->s=statement;
	isl->next=NULL;

	if(list)
		{
		for(aux=list; aux->next; aux=aux->next);
		aux->next=isl;
		return list;
		}

	return isl;
}

is_statement* insert_statement_write(is_write_stat* iws)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_write_stat;
	is->data_statement.u_write_stat=iws;

	return is;
}

is_statement* insert_statement_for(is_for_stat* ifs)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_for_stat;
	is->data_statement.u_for_stat=ifs;

	return is;
}

is_statement* insert_statement_assgn(is_assgn_stat* ias)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_assgn_stat;
	is->data_statement.u_assgn_stat=ias;

	return is;
}

is_statement* insert_statement_call(is_call_stat* ics)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_call_stat;
	is->data_statement.u_call_stat=ics;

	return is;
}


is_statement* insert_statement_if(is_if_stat* ifs)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_if_stat;
	is->data_statement.u_if_stat=ifs;

	return is;
}

is_statement* insert_statement_while(is_while_stat* iws)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_while_stat;
	is->data_statement.u_while_stat=iws;

	return is;
}

is_statement* insert_statement_if_else(is_if_else_stat* ifs)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_if_else_stat;
	is->data_statement.u_if_else_stat=ifs;

	return is;
}

is_statement* insert_statement_return(is_return_statement* irs)
{
	is_statement* is=(is_statement*)malloc(sizeof(is_statement));
	is->disc_d=d_return_stat;
	is->data_statement.u_return_stat=irs;

	return is;
}



is_write_stat* insert_write_stat(int line, char* var)
{
	is_write_stat* iws=(is_write_stat*)malloc(sizeof(is_write_stat));
	iws->var=(char*)strdup(var);
	iws->codeline=line;

	return iws;
}


is_write_stat *insert_write_stat_int(int line , int i){
	is_write_stat* iws=(is_write_stat*)malloc(sizeof(is_write_stat));
	iws->var = "";
	iws->type = integer;
	iws->values.i=i;	
	iws->codeline=line;

	return iws;

}

is_write_stat *insert_write_stat_doub(int line , double d){
	is_write_stat* iws=(is_write_stat*)malloc(sizeof(is_write_stat));
	iws->var = "";
	iws->type = doub;
	iws->values.d=d;	
	iws->codeline=line;
	
	return iws;

}

is_write_stat *insert_write_stat_char(int line , char c){
	is_write_stat* iws=(is_write_stat*)malloc(sizeof(is_write_stat));
	iws->var = "";
	iws->type = character;
	iws->values.c=c;	
	iws->codeline=line;

	return iws;

}

is_write_stat *insert_write_stat_bool(int line , boolean b){
	is_write_stat* iws=(is_write_stat*)malloc(sizeof(is_write_stat));
	iws->var = "";
	iws->type = bool;
	iws->values.b=b;	
	iws->codeline=line;

	return iws;

}

is_call_stat* insert_call_stat(int line, char* var,is_call_arg_list *ical)
{
	is_call_stat* ics=(is_call_stat*)malloc(sizeof(is_call_stat));
	ics->proc=(char*)strdup(var);
	ics->codeline=line;
	ics->ical = ical;
	return ics;
}


is_call_arg *insert_call_args_int(int valor,basic_type type){
	is_call_arg *novo = (is_call_arg*)malloc(sizeof(is_call_arg));
	novo->name = "";
	novo->type=type;
	novo->data_args.i=valor;
	return novo;
}

is_call_arg *insert_call_args_doub(double valor,basic_type type){
	is_call_arg *novo = (is_call_arg*)malloc(sizeof(is_call_arg));	
	novo->name = "";
	novo->type=type;
	novo->data_args.d=valor;
	return novo;
}

is_call_arg *insert_call_args_char(char valor,basic_type type){
	is_call_arg *novo = (is_call_arg*)malloc(sizeof(is_call_arg));
	novo->name ="";
	novo->type=type;
	novo->data_args.c=valor;
	return novo;
}

is_call_arg *insert_call_args_bool(boolean valor,basic_type type){
	is_call_arg *novo = (is_call_arg*)malloc(sizeof(is_call_arg));
	novo->name="";
	novo->type=type;
	novo->data_args.b=valor;
	return novo;
}


is_call_arg* insert_call_args_value(char *name){
	is_call_arg *novo = (is_call_arg*)malloc(sizeof(is_call_arg));
	novo->name=(char *)strdup(name);
	return novo;
}

is_call_arg_list *insert_call_agr_list(is_call_arg_list *ical,is_call_arg *ica){
	is_call_arg_list* novo=(is_call_arg_list*)malloc(sizeof(is_call_arg_list));
	is_call_arg_list* aux;
	novo->ca=ica;
	novo->next=NULL;
	int pos=0;
	if(ical)
		{
		for(aux=ical; aux->next; aux=aux->next,pos++);
		aux->pos=pos;
		aux->next=novo;
		return ical;
		}

	return novo;
}

is_args_vardec *insert_arg_vardec(int line,basic_type type, char *name){
	is_args_vardec *novo = (is_args_vardec*)malloc(sizeof(is_args_vardec));
	novo->type = type;
	novo->name = (char*)strdup(name);
	novo->codeline=line;
	return novo;
}

is_args_vardec_list *insert_arg_vardec_list(is_args_vardec_list *iavl,is_args_vardec *iav){
	is_args_vardec_list* novo=(is_args_vardec_list*)malloc(sizeof(is_args_vardec_list));
	is_args_vardec_list* aux;
	novo->av=iav;
	novo->next=NULL;
	int pos=0;
	if(iavl)
		{
		for(aux=iavl; aux->next; aux=aux->next,pos++);
		aux->pos=pos;
		aux->next=novo;
		return iavl;
		}

	return novo;
}



is_if_stat* insert_if_stat(int line, is_expression_list* boolean, is_statement_list* list)
{
	is_if_stat* ifs=(is_if_stat*)malloc(sizeof(is_if_stat));
	ifs->boolean=boolean;
	ifs->statement_list=list;
	ifs->codeline=line;

	return ifs;
}

is_expression* insert_expression(int line, char* cod, bol_type tipo)
{
	is_expression* iex=(is_expression*)malloc(sizeof(is_expression));
	iex->cod=cod;
	iex->type=tipo;
	iex->codeline=line;

	return iex;
}


is_expression_list *insert_expression_list(is_expression_list* list, is_expression* ex)
{
	is_expression_list* iexl=(is_expression_list*)malloc(sizeof(is_expression_list));
	is_expression_list* aux;
	iexl->expression=ex;
	iexl->next=NULL;

	if(list)
		{
		for(aux=list; aux->next; aux=aux->next);
		aux->next=iexl;
		return list;
		}

	return iexl;
}



is_if_else_stat* insert_if_else_stat(int line, is_expression_list* boolean, is_statement_list* list,is_statement_list* list2,int n_if)
{
	is_if_else_stat* ifs=(is_if_else_stat*)malloc(sizeof(is_if_else_stat));
	ifs->boolean=boolean;
	ifs->statement_list=list;
	ifs->statement_list2=list2;
	ifs->n_if=n_if;
	ifs->codeline=line;

	return ifs;
}

is_while_stat* insert_while_stat(int line, is_expression_list* boolean, is_statement_list* list, int n_while)
{
	is_while_stat* iws=(is_while_stat*)malloc(sizeof(is_while_stat));
	iws->boolean=boolean;
	iws->statement_list=list;
	iws->codeline=line;
	iws->n_while=n_while;

	return iws;
}

is_for_stat* insert_for_stat(int line, is_expression_list* boolean, is_statement_list* list,is_statement* inicial,is_statement* loop_stat,int n_for)
{
	is_for_stat* ifs=(is_for_stat*)malloc(sizeof(is_for_stat));
	ifs->boolean=boolean;
	ifs->list=list;
	ifs->inicial=inicial;
	ifs->loop_stat=loop_stat;
	ifs->codeline=line;
	ifs->n_for=n_for;

	return ifs;
}

is_assgn_stat_2* update_variaveis(is_assgn_stat_2 *variaveis, char* name,basic_type type){
	is_assgn_stat_2 *novo = (is_assgn_stat_2*)malloc(sizeof(struct _var));
	novo->disc_d=type;
	novo->var=(char*)strdup(name);
	if(variaveis==NULL){
		variaveis=novo;
		novo->next=NULL;
	}
	else{
		novo->next = variaveis;
	}
	return novo;	
}

void deleteAll(is_assgn_stat_2 *variaveis){
	is_assgn_stat_2 *next = variaveis;
	is_assgn_stat_2 *current = variaveis;
	while(current!=NULL){
		next = (current)->next;
		free(current);
		current = next;
	}
}



int is_int(char* name,is_assgn_stat_2* variaveis)
{
	is_assgn_stat_2* aux;

	for(aux=variaveis;aux;aux=aux->next){
		if(strcmp(name,aux->var)==0 && aux->disc_d==integer) return 1;
	}
	
	return 0;
}
