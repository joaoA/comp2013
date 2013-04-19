#ifndef _STRUCTURES_
#define _STRUCTURES_

typedef enum {d_char, d_int} disc_declarator;
typedef enum {d_intlit, d_charlit, d_strlit, d_id, u_infix_exp, u_unary_exp, d_null } disc_terminal;
typedef enum {is_or, is_and, is_eq, is_ne, is_lt, is_gt, is_le, is_ge, is_add, is_sub, is_mul, is_div, is_mod, is_not, is_minus, is_plus, is_addr, id_deref, is_store, is_call, is_print, is_atoi, is_itoa }is_operator;
typedef enum {d_if_else, d_return, d_while} disc_statement;
typedef enum {d_declarator, d_array_declarator} disc_declaration;
typedef enum {d_func_declaration, d_declaration} disc_start;

/*is_expression*/
typedef struct _s1{
	disc_terminal d_terminal;
	union{
		// adicionar o que falta
		int number;
		char character;	
		char *string;
		struct is_infix_expression *u_infix_exp;
		struct is_unary_expression *u_unary_exp;
	}data_expression;


}is_expression;

/*is_infix_expression*/
typedef struct _s2{
	is_expression *expression1;
	is_operator oprtor;
	is_expression *expression2;
}is_infix_expression;

/*is_unary_expression*/
typedef struct _s3{
	is_operator oprtor;
	is_expression *expression1;
}is_unary_expression;

typedef struct  _s7{
	disc_statement d_statement;
	union{
		struct is_return *u_return;
		struct is_while *u_while;
		struct is_if_else *u_if_else;
	}data_statement;
	struct _s7 *next;
}is_statement;

typedef struct  _s4{
	is_expression *expression1;
}is_return;

typedef struct  _s5{
	is_expression *expression1;
	is_statement *statement1;
}is_while;

typedef struct  _s6{
	is_expression *expression1;
	is_statement *statement1;
	is_statement *statement2;
}is_if_else;

typedef struct _s8{
	struct _s8 *next;
}is_pointer;

typedef struct _s9{
	disc_declarator d_declarator;
	is_pointer *pointer;
	is_expression *id;
}is_param_declaration;

typedef struct _s14{
	is_pointer *pointer;
	is_expression *id;
	is_expression *intlit;
}is_array_declarator;

typedef struct _s15{
	is_pointer *pointer;
	is_expression *id;
}is_declarator;

typedef struct _s16{
	disc_declarator d_declarator;
	disc_declaration d_declaration;
	union{
		struct is_declarator *u_declarator;
		struct is_array_declarator *u_array_declarator;
	}data_declaration;
	struct _s16 *next;
}is_declaration;

typedef struct _s10{
	is_statement *statement1;
	is_declaration *declaration1;
}is_func_body;

typedef struct _s11{
	is_pointer *pointer;
	is_expression *id;
	is_param_declaration *param_declaration;
}is_func_declarator;

typedef struct _s12{
	disc_declarator d_declarator;
	is_func_declarator *func_declarator;
	is_func_body *func_body;
}is_func_definition;

typedef struct _s13{
	disc_declarator d_declarator;
	is_func_declarator *func_declarator;
}is_func_declaration;




/*is_start*/
typedef struct _s17{
	disc_start d_start;
	union{
		struct is_declaration *u_declaration;
		struct is_func_declaration *u_func_declaration;
	}data_start;
	struct _s17 *next;
}is_start;

#endif