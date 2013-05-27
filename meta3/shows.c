#include "shows.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void add_space(int n)
{
	int i;

	for(i = 0;i<n;i++)
		printf("  ");
}

void show_program(is_node * program, int ident)
{
	is_node * aux = program;
	disc_node tipo;
	if(aux!=NULL){
		tipo = aux->d_node;
		if(aux->d_node!=d_null)
			show_expression(aux, ident);
		if(aux->child!=NULL && (tipo != d_null && tipo != d_stat && tipo != d_infix_exp && tipo != d_unary_exp && tipo != d_param_list))
			show_program(aux->child, ident+1);
		else if(aux->child!=NULL ){show_program(aux->child, ident);}
		if(aux->next!=NULL)
			show_program(aux->next, ident);
	}
}

void show_expression(is_node * no, int ident){

	disc_node tipo = no->d_node;

	//printf("ENTROU AQUI!\n");
	if(tipo != d_null && tipo != d_stat && tipo != d_infix_exp && tipo != d_unary_exp && tipo != d_param_list) {
		add_space(ident);
	}

	switch(tipo){
		case d_intlit:
			printf("IntLit(%d)\n", no->data.number); break;
		case d_charlit:
			printf("ChrLit(\'%s\')\n",no->data.string); break;
		case d_strlit:
			printf("StrLit(\"%s\")\n",no->data.string); break;
		case d_id:
			printf("Id(%s)\n",no->data.string); break;
		case d_int:
			printf("Int\n"); break;
		case d_char:
			printf("Char\n"); break;
		case d_null:
			//printf("D_NULL\n"); 
		case d_stat:
			break;
		case d_infix_exp:
			break;
		case d_unary_exp:
			break;
		case d_or: 
			printf("Or\n"); break;
		case d_and:
			printf("And\n"); break;
		case d_eq:
			printf("Eq\n"); break;
		case d_ne:
			printf("Ne\n"); break;
		case d_lt:
			printf("Lt\n"); break;
		case d_gt:
			printf("Gt\n"); break;
		case d_le:
			printf("Le\n"); break;
		case d_ge:
			printf("Ge\n"); break;
		case d_add:
			printf("Add\n"); break;
		case d_sub:
			printf("Sub\n"); break;
		case d_mul:
			printf("Mul\n"); break;
		case d_div:
			printf("Div\n"); break;
		case d_mod:
			printf("Mod\n"); break;
		case d_not:
			printf("Not\n"); break;
		case d_minus:
			printf("Minus\n"); break;
		case d_plus:
			printf("Plus\n"); break;
		case d_addr:
			printf("Addr\n"); break;
		case d_deref:
			printf("Deref\n"); break;
		case d_store:
			printf("Store\n"); break;
		case d_call:
			printf("Call\n"); break;
		case d_print:
			printf("Print\n"); break;
		case d_atoi:
			printf("Atoi\n"); break;
		case d_itoa:
			printf("Itoa\n"); break;
		case d_if:
			printf("IfElse\n"); break;
		case d_if_else:
			printf("IfElse\n"); break;
		case d_while:
			printf("While\n"); break;
		case d_declarator:
			printf("Declarator\n"); break;
		case d_array_declarator:
			printf("ArrayDeclarator\n"); break;
		case d_func_declarator:
			printf("FuncDeclarator\n"); break;
		case d_func_declaration:
			printf("FuncDeclaration\n"); break;
		case d_func_definition:
			printf("FuncDefinition\n"); break;
		case d_declaration:
			printf("Declaration\n"); break;
		case d_param_declaration:
			printf("ParamDeclaration\n"); break;
		case d_param_list:
			break;
		case d_print_null:
			printf("Null\n"); break;
		case d_return:
			printf("Return\n"); break;
		case d_pointer:
			printf("Pointer\n"); break;
		case d_func_body:
			printf("FuncBody\n"); break;
		case d_compound_stat:
			printf("CompoundStat\n"); break;


	}
}

