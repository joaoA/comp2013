#include "structures.h"


is_node* insert_number(disc_node type, int number);
is_node* insert_string(disc_node type, char *string);
is_node* insert_itoa(disc_node type, is_node *son1, is_node *son2);
is_node* insert_printf(disc_node type, is_node *son1);
is_node* insert_atoi(disc_node type, is_node *son1);
is_node* insert_link(is_node *expression1, is_node *expression2);
is_node* insert_token(disc_node type);
is_node* insert_infix_expression(disc_node type, is_node *son1, is_node *son2);
is_node* insert_unary_expression(disc_node type, is_node *son1);
is_node* insert_return(disc_node type, is_node *son1);
is_node* insert_while(disc_node type, is_node *expression1, is_node *statement1);
is_node* insert_if(disc_node type, is_node *expression1, is_node *statement1);
is_node* insert_if_else(disc_node type, is_node *expression1, is_node *statement1, is_node *statement2);
is_node* insert_deref(disc_node type, is_node *son1);
is_node* insert_declarator(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3);
is_node* insert_declaration(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3);
is_node* insert_param_declaration(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3);
is_node* insert_param_list(disc_node type, is_node *expression1, is_node *expression2);
is_node* insert_function_declarator(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3);
is_node* insert_function_declaration(disc_node type, is_node *expression1, is_node *expression2);
is_node* insert_function_definition(disc_node type, is_node *expression1, is_node *expression2, is_node *expression3);
is_node* insert_nulls(is_node *expression1, is_node *expression2);
is_node* insert_start_declaration(disc_node type, is_node *expression1, is_node *expression2);
is_node *reverse(is_node *node);
is_node* insert_func_body(disc_node type, is_node *expression1, is_node *expression2);
int compoundStatCounter(is_node *node);
is_node* insert_compound(disc_node type, is_node *expression1);
is_node* insert_add(disc_node type, is_node *expression1,is_node *expression2);
is_node* insert_call(disc_node type, is_node *son1);
is_node * insert_null_node();
int flatten(is_node * lista, is_node * actual);
int contaStatements(is_node * head);

