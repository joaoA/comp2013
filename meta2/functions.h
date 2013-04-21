#include "structures.h"


is_expression* insert_INTLIT(int);
is_expression* insert_STRLIT(char*);

is_start* insert_start(int opt, is_start *list, is_declaration *declaration , is_func_declaration *func_declaration, is_func_definition *func_definition);
