#include "structures.h"
#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_

typedef enum {INTe, CHARe} data_type;

typedef struct _t2{
	data_type type;
	int pointers;
	int size;
} element_data;

//lista ligada de simbolos - um ambiente/registo de activação
typedef struct _t1{	
	char name[32];
	disc_node type;
	element_data type_data;
	int offset;		//futura posição na frame, caso seja uma variavel -1, se for uma procedure.
	struct _t1 *next;
} table_element;


//lista de procedimentos definidos no programa
typedef struct _t4{
	char* name;
	struct _t4 *next;
	table_element *locals;
}environment_list;

//Estrutura que guarda TODOS os simbolos de um programa: o ambiente "global" e a lista de ambientes
typedef struct _t5{
	table_element* global;
	environment_list* procs;
}prog_env;
#endif
