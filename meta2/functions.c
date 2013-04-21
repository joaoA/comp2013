#include "structures.h"
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
	
	son1->next = son2;
	ie->child = son1;

	printf("ITOA\n");
	return ie;	
}

is_node* insert_printf(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	
	ie->child = son1;

	printf("PRINT\n");
	return ie;	
}

is_node* insert_atoi(disc_node type, is_node *son1){
	is_node* ie=(is_node*)malloc(sizeof(is_node));
	ie->d_node=type;			//Coloca etiqueta a informar que é um numero
	
	ie->child = son1;

	printf("ATOI\n");
	return ie;	
}

is_node* insert_link(is_node *expression1, is_node *expression2){
	is_expression_list* aux;
			
	for(aux=expression1; aux->next!=NULL; aux=aux->next);

	expression1->next = expression2;
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

	son1->next = son2;
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

	expression1->next = statement1;
	ie->child = expression1;

	return ie;
}




