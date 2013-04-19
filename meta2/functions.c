#include "functions.h"
#include "structures.h"
#include <stdlib.h>


is_expression* insert_INTLIT(int number)
{
	is_expression* ie=(is_expression*)malloc(sizeof(is_expression));
	ie->disc_d=d_intlit;			//Coloca etiqueta a informar que é um numero
	ie->data_expr.number=number;	//Guarda o conteúdo
	return ie;		
}

is_expression* insert_STRLIT(char *string)
{
	is_expression* ie=(is_expression*)malloc(sizeof(is_expression));
	ie->disc_d=d_intlit;			//Coloca etiqueta a informar que é um numero
	ie->data_expr.string=string;	//Guarda o conteúdo
	return ie;		
}