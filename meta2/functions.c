#include "structures.h"
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>


is_expression* insert_INTLIT(int number)
{
	is_expression* ie=(is_expression*)malloc(sizeof(is_expression));
	ie->d_terminal=d_intlit;			//Coloca etiqueta a informar que é um numero
	ie->data_expression.number=number;	//Guarda o conteúdo
	return ie;		
}

is_expression* insert_STRLIT(char *string)
{
	is_expression* ie=(is_expression*)malloc(sizeof(is_expression));
	ie->d_terminal=d_intlit;			//Coloca etiqueta a informar que é um numero
	ie->data_expression.string=string;	//Guarda o conteúdo
	return ie;		
}