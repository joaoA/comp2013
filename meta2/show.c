#include "shows.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>


/*TODO -> fazer os nivels, conta-los de alguma forma no show_program e depois antes do print de cada cena
fazer um while e ir imprimindo até chegar ao ao nivel onde estás*/ 

int nivel_actual=0;

void show_program(is_expression* program)
{	//mostra a árvore que acabou de ser construida
	/*correr a is_start e chamar funçoes para correr as outras estruturas e fazer print de chavetas / parentises */
	/* ... niveis da arvore*/
	show_expression(0,program);

}

void show_expression(int nivel, is_expression* ie)
{
	switch(ie->disc_terminal)
	{
	case d_intlit: 
			printf("INTLIT(%d)\n",ie->data_expression.number );
			break;
	case d_charlit:
			printf("INTLIT(%d)\n",ie->data_expression.number );	 
			break;

	default:
		printf("DEU MERDA\n");
		break;

}

