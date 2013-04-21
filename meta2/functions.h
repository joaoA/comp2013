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