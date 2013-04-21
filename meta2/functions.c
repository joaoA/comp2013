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



is_start* insert_start(int opt,is_start *list, is_declaration *declaration , is_func_declaration *func_declaration, is_func_definition *func_definition)
{
	/* por enquanto isto fica comentado até se irem fazendo as funçoes para baixo */

	is_start *is=(is_start*)malloc(sizeof(is_start));
	is_start* aux;
	is->next=NULL;

	if(opt==0){
		is_declaration *id = (is_declaration*)malloc(sizeof(is_declaration));
		/*id=insert_declartion(declaration);*/
		printf("\ndeclaration\n\n");

		is->d_start=d_declaration;
		// is->data_start.u_declaration = id;
		if(list!=NULL){
			for(aux=list; aux->next!=NULL; aux=aux->next); /*procura ultimo no' e adiciona*/
			aux->next=is;
		}
		else
			return is;   /* caso seja o primeiro e unico elemento da lista  */


	}
	else if (opt==1){
		is_func_definition *ifd = (is_func_definition*)malloc(sizeof(is_func_definition));
		// ifd=insert_func_definition(func_definition);
		printf("\nfunc_definition\n\n");

		is->d_start=d_func_definition;
		// is->data_start.u_func_definition = ifd;
		if(list!=NULL){
			for(aux=list; aux->next!=NULL; aux=aux->next); /*procura ultimo no' e adiciona*/
			aux->next=is;
		}
		else
			return is;		/* caso seja o primeiro e unico elemento da lista  */

	}
	else if(opt==2){
		is_func_declaration *ifdec = (is_func_declaration*)malloc(sizeof(is_func_declaration));
		// ifdec=insert_func_declartion(func_declaration);
		printf("\nfunc_declaration\n\n");

		is->d_start=d_func_declaration;
		// is->data_start.u_func_declaration = ifdec;
		if(list!=NULL){
			for(aux=list; aux->next!=NULL; aux=aux->next); /*procura ultimo no' e adiciona*/
			aux->next=is;
		}
		else
			return is;		/* caso seja o primeiro e unico elemento da lista  */

	}

	return list;



}