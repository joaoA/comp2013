#ifndef _STRUCTURES_
#define _STRUCTURES_


typedef enum {functionDefinition, functionDeclaration,declaration} disc_start;
typedef enum {d_intlit, d_charlit, d_strlit, d_id, , d_int , d_char, d_pointer } disc_terminal;
typedef enum {is_or, is_and, is_eq, is_ne, is_lt, is_gt, is_le, is_ge, is_add, is_sub, is_mul, is_div, is_mod, is_not, is_minus, is_plus, is_addr, id_deref, is_store, is_call, is_print, is_atoi, is_itoa }is_operator;



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





/*is_new_twelve*/
typedef struct _s{
}is_new_twelve;

/*is_declaration*/
typedef struct _s{
}is_declaration;



/*is_functionDeclaration;*/
typedef struct _s{
}is_functionDeclaration;



/*is_functionDefinition*/
typedef struct _s{
}is_functionDefinition;



/*******************************************************/
/*****					start 					   *****/
/*******************************************************/

/*is_start*/
typedef struct _s{
	disc_start disc_s;		/* functionDefinition || functionDeclaration || declaration */
	is_new_twelve *isNewt;
	union{
		is_functionDefinition* isFuncDef;
		is_functionDeclaration* isFuncec;
		is_declaration* isDec;
	}data_start;
	struct _s1 *next;   /* start nao precisa disto!? n tem recursividade.... */
}is_start;



#endif