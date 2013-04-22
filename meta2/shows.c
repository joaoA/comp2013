#include "shows.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void add_space(int n)
{
	int i;

	for(i = 0 ;i<n;i++)
		printf("  ");
}

void show_program(is_node * program, int ident)
{
	is_node * aux = program;
	
	if(aux!=NULL)
		add_space(ident);
		show_expression(aux);
	if(aux->child!=NULL)
		show_program(aux->child, ident++);
	if(aux->next!=NULL)
		show_program(aux->next, ident);
}

void show_expression(is_node * no){

	disc_node tipo = no->d_node;

	//printf("ENTROU AQUI!\n");

	switch(tipo){
		case d_intlit:
			printf("IntLit(%d)\n", no->data.number);
		break;
		case d_charlit:
			printf("ChrLit('%s')\n",no->data.string);
		break;
		case d_strlit:
			printf("StrLit(\"%s\")\n",no->data.string);
		break;
		case d_id:
			printf("Id(%s)\n",no->data.string);
		break;
		case d_int:
			printf("d_int\n");
		break;
		case d_char:
			printf("d_char\n");
		break;
		case d_null:
			//printf("d_null\n");
		break;
		case d_infix_exp:
			printf("d_infix_expression\n");
		break;
		case d_unary_exp:
			printf("d_unary_expression\n");
		break;
		case d_or:
			printf("is_or\n");
		break;
		case d_and:
			printf("is_and\n");
		break;
		case d_eq:
			printf("is_eq\n");
		break;
		case d_ne:
			printf("is_ne\n");
		break;
		case d_lt:
			printf("is_lt\n");
		break;
		case d_gt:
			printf("is_gt\n");
		break;
		case d_le:
			printf("is_le\n");
		break;
		case d_ge:
			printf("is_ge\n");
		break;
		case d_add:
			printf("is_add\n");
		break;
		case d_sub:
			printf("is_sub\n");
		break;
		case d_mul:
			printf("is_mul\n");
		break;
		case d_div:
			printf("is_div\n");
		break;
		case d_mod:
			printf("is_mod\n");
		break;
		case d_not:
			printf("is_not\n");
		break;
		case d_minus:
			printf("is_sub\n");
		break;
		case d_plus:
			printf("is_plus\n");
		break;
		case d_addr:
			printf("is_addr\n");
		break;
		case d_deref:
			printf("is_deref\n");
		break;
		case d_store:
			printf("is_store\n");
		break;
		case d_call:
			printf("is_call\n");
		break;
		case d_print:
			printf("is_print\n");
		break;
		case d_atoi:
			printf("is_atoi\n");
		break;
		case d_itoa:
			printf("is_itoa\n");
		break;
		case d_if:
			printf("d_if\n");
		break;

		case d_if_else:
			printf("d_ifelse\n");
		break;
		case d_while:
			printf("d_while\n");
		break;

		case d_declarator:
			printf("d_declarator\n");
		break;

		case d_array_declarator:
			printf("d_array_declarator\n");
		break;

		case d_func_declarator:
			printf("d_func_declarator\n");
		break;

		case d_func_declaration:
			printf("d_func_declaration\n");
		break;
		case d_func_definition:
			printf("d_func_definition\n");
		break;

		case d_declaration:
			printf("d_declaration\n");
		break;
		case d_param_declaration:
			printf("d_param_declaration\n");
		break;
		case d_param_list:
			printf("d_param_list\n");
		break;
		case d_return:
			printf("d_return\n");
		break;
		case d_pointer:
			printf("d_pointer\n");
		break;
		default:
			printf("MERDA\n");
			break;


	}
}
