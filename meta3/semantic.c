#include "structures.h"
#include "symbol_table.h"
#include "semantic.h"
#include "shows.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
 	switch(ip->d_node)
	{
	//case d_declaration: semantic_analysis_procedure(pe, ip->data_block.u_procedure);  break;
	case d_declaration: semantic_analysis_globals(pe, ip); break;
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
			break;
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
			printf("Error: %s already defined!\n", stringAux->data.string);
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
		default: break;
	}

	for(aux=node; aux; aux=aux->next){
		switch(aux->d_node){
			case d_id: strcpy(el->name, aux->data.string); break;
			case d_intlit: el->type_data.size = aux->data.number; break;
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