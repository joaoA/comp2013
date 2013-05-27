#ifndef _STRUCTURES_
#define _STRUCTURES_


typedef enum {d_char, d_int, d_intlit, d_charlit, d_strlit, d_id, d_infix_exp, d_unary_exp, d_null,
			d_or, d_and, d_eq, d_ne, d_lt, d_gt, d_le, d_ge, d_add, d_sub, d_mul, d_div, d_mod, d_not, 
			d_minus, d_plus, d_addr, d_deref, d_store, d_call, d_print, d_atoi, d_itoa, d_print_null,
			d_if, d_if_else, d_return, d_while, d_declarator, d_array_declarator, d_stat, d_compound_stat, 
			d_func_declaration, d_declaration, d_param_declaration, d_pointer, d_param_list, d_func_definition, 
			d_func_declarator, d_func_body} disc_node; 

typedef union {
	int number;
	char* string;
}info;

typedef struct _s1
{
	disc_node d_node;
	info data;

	struct _s1 *child;
	struct _s1 *next;
}is_node;


#endif

