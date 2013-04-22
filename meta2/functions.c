#include "structures.h"
#include "shows.h"
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>


is_node* insert_number(disc_node type, int number){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	ie->data.number=number;	//Guarda o conteúdo
	return ie;		
}

is_node* insert_string(disc_node type, char *string){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	ie->data.string=string;	//Guarda o conteúdo
	return ie;		
}

is_node* insert_itoa(disc_node type, is_node *son1, is_node *son2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	
	is_node *aux = son1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = son2;
	ie->child = son1;

	return ie;	
}

is_node* insert_printf(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	
	ie->child = son1;

	return ie;	
}

is_node* insert_atoi(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	
	ie->child = son1;

	return ie;	
}

is_node* insert_link(is_node *expression1, is_node *expression2){
	
	is_node *aux = expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression2;
	return expression1;	
}

is_node* insert_token(disc_node type){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	return ie;		
}

is_node* insert_infix_expression(disc_node type, is_node *son1, is_node *son2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = son1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = son2;
	ie->child = son1;

	return ie;
}

is_node* insert_unary_expression(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	ie->child = son1;

	return ie;
}

is_node* insert_return(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	ie->child = son1;

	return ie;
}

is_node* insert_while(disc_node type, is_node *expression1, is_node *statement1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = statement1;
	ie->child = expression1;

	return ie;
}

is_node* insert_if(disc_node type, is_node *expression1, is_node *statement1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = statement1;
	ie->child = expression1;

	return ie;
}

is_node* insert_if_else(disc_node type, is_node *expression1, is_node *statement1, is_node *statement2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	/*show_program(statement1->child,0);
	printf("\nexpression2\n");
	//sshow_program(statement1, 0);
	printf("\n");
	*/
	is_node *aux2 = expression1;	
	while(aux2->next != NULL){ aux2=aux2->next;}
	is_node *aux = statement1;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = statement2;
	ie->child = expression1;

	return ie;
}

is_node* insert_deref(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	ie->child = son1;

	return ie;
}

is_node* insert_declarator(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;
	
	is_node *aux2 = expression1;
	while(aux2->next != NULL){aux2=aux2->next;}
	is_node *aux = expression2;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression3;
	ie->child = expression1;

	return ie;
}

is_node* insert_declaration(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	/*printf("EXPRESSION1\n");
	show_program(expression1, 1);
	printf("\nEXPRESSION2\n");
	show_program(expression2, 1);
	printf("\nEXPRESSION3\n");
	show_program(expression3, 1);
	*/
	is_node *aux2 = expression1;
	while(aux2->next != NULL){ aux2=aux2->next;}
	is_node *aux = expression2;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression3;
	ie->child = expression1;


	return ie;
}

is_node* insert_param_declaration(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux2 = expression1;	
	while(aux2->next != NULL){ aux2=aux2->next;}
	is_node *aux = expression2;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression3;
	ie->child = expression1;

	return ie;
}

is_node* insert_param_list(disc_node type, is_node *expression1, is_node *expression2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux =expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression2;
	ie->child = expression1;

	return ie;
}

is_node* insert_function_declarator(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux2 = expression1;
	while(aux2->next != NULL){ aux2=aux2->next;}
	is_node *aux = expression2;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression3;
	ie->child = expression1;

	return ie;
}

is_node* insert_function_declaration(disc_node type, is_node *expression1, is_node *expression2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression2;
	ie->child = expression1;

	return ie;
}

is_node* insert_function_definition(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux2 = expression1;	
	while(aux2->next != NULL){ aux2=aux2->next;}
	aux2->next = expression2;
	is_node *aux = expression2;	
	aux2->next = aux;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression3;
	ie->child = expression1;

	return ie;
}

is_node* insert_nulls(is_node *expression1, is_node *expression2){
	is_node* ie=expression2->next;
	expression2->next = expression1;

	is_node* aux=expression1;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = ie;

	/*printf("EXPRESSION1\n");
	show_program(expression2,0);
	printf("\n");*/
	return expression2;
}

is_node* insert_start_declaration(disc_node type, is_node *expression1, is_node *expression2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression2;
	ie->child = expression1;

	return ie;
}

is_node *reverse(is_node *node){
	is_node *ie = NULL, *next;

	while(node!=NULL){
		next = node->next;
		node->next = ie;
		ie = node;
		node = next;
	}

	return ie;
}

is_node* insert_func_body(disc_node type, is_node *expression1, is_node *expression2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;
	while(aux->next != NULL){aux=aux->next;}
	aux->next = expression2;
	ie->child = expression1;

	return ie;
}

int compoundStatCounter(is_node *node){
     int conta = 0;
     is_node *tmp = node;
     while (tmp != NULL)
     {
          if (tmp->d_node != d_null)
          {
               ++conta;

          }
          tmp = tmp->next;
     }
     return conta;
}

is_node* insert_compound(disc_node type, is_node *expression1){

	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	ie->child = expression1;

	return ie;
}

is_node* insert_add(disc_node type, is_node *expression1, is_node *expression2){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	is_node *aux = expression1;	
	while(aux->next != NULL){ aux=aux->next;}
	aux->next = expression2;
	ie->child = expression1;


	return ie;
}

is_node* insert_call(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = type;

	ie->child = son1;

	return ie;
}

is_node * insert_null_node(){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node = d_print_null;

	return ie;
}


/* Funcao que calcula o numero de statements "reais" */
int flatten(is_node * lista, is_node * actual)
{
     // Adiciona na lista
    // lista = associaNode(lista, actual);
     if ((actual->d_node != d_null) && (actual->d_node != d_compound_stat)) return 1;     
     is_node * tmp = actual->next;
     while (tmp != NULL)
     {
          if (flatten(lista, tmp) == 1) return 1;
          tmp = tmp->next;
     }
     tmp = actual->child;
     while (tmp != NULL)
     {
          if (flatten(lista, tmp) == 1) return 1;
          tmp = tmp->next;
     }
     return 0;
}
int contaStatements(is_node * head)
{
     // Coloca tudo numa lista
    // struct node * lista = createNode(_IGNORE, (union _data) -1);
     return flatten(head, head);
     
     return 0;
}


