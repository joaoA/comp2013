#ifndef _STRUCTURES_
#define _STRUCTURES_

#include "symbol_table.h"


int line;

typedef enum{false,true} boolean;

//verificar se é possivel eliminar esta estrutura
typedef struct _var{
	struct _var* next;
	basic_type disc_d;
	char* var;
}is_assgn_stat_2;


typedef struct _is_arg_call{
	basic_type type;
	char *name;
	union{
		int i;
		double d;
		char c;
		boolean b;
	}data_args;
}is_call_arg;

typedef struct _is_call_arg_list{
	struct _is_call_arg_list *next;
	is_call_arg *ca;
	int pos;
}is_call_arg_list;

typedef struct _is_args_vardec	{
	basic_type type;
	char *name;
	int veri;
	struct _ex2* list;
	union{
		int i;
		double d;
		char c;
		boolean b;
	}data_args;
	int codeline;
}is_args_vardec;

typedef struct _is_args_vardec_list{
	struct _is_args_vardec_list *next;
	int pos;
	is_args_vardec *av;
}is_args_vardec_list;


/*is_call_stat ->(<proc:char*>)*/
typedef struct _s6a{
	char* proc;
	is_call_arg_list *ical;
	int codeline;
}is_call_stat;

/*is_write_stat ->(<var:char*>)*/
typedef struct _s6{
	char* var;
	basic_type type;
	union{
		int i;
		double d;
		char c;
		boolean b;
	}values;
	int codeline;
}is_write_stat;

typedef struct _r1{
	char* name;
	int codeline;
}is_return_statement;

/*is_assgn_stat ->(<var:char*><val:int>)*/
//typedef enum {d_intassgn, d_doubassgn, d_charassgn} disc_assgn_stat; Igualmente desnecessario, pois já há o basic type

//verificar se é possivel retirar union e basic_type
typedef struct _a7{
	basic_type disc_d;
	char* var;
	union{
		char c;
		boolean b;
	}data_assgn_stat;
	int codeline;
	struct _ex2* list;
}is_assgn_stat;


typedef enum {d_write_stat, d_assgn_stat, d_call_stat,d_if_stat,d_if_else_stat,d_while_stat,d_for_stat,d_return_stat} disc_statement;


typedef struct _s5{
	disc_statement disc_d;
	union{
		is_write_stat *u_write_stat;
		is_assgn_stat *u_assgn_stat;
		is_call_stat *u_call_stat;
		struct _if1* u_if_stat;
		struct _if2* u_if_else_stat;
		struct _wl* u_while_stat;
		struct _for1* u_for_stat;
		struct _r1* u_return_stat;
	}data_statement;
}is_statement;

/*is_stament_list*/
typedef struct _s8{
	struct _s8 *next;
	is_statement *s;
}is_statement_list;

typedef struct _wl{
	struct _ex2* boolean;
	int codeline;
	int n_while;
	is_statement_list* statement_list;

}is_while_stat;

typedef enum {var,not_var} bol_type;

typedef struct _ex1{

	int codeline;
	char* cod;
	bol_type type;

}is_expression;


typedef struct _ex2{

	struct _ex1* expression;
	struct _ex2* next;

}is_expression_list;

typedef struct _if1{
	int codeline;
	is_expression_list* boolean;
	is_statement_list* statement_list;
}is_if_stat;

typedef struct _if2{
	is_expression_list* boolean;
	int codeline;
	int n_if;
	is_statement_list* statement_list;
	is_statement_list* statement_list2;
}is_if_else_stat;

typedef struct _for1{
	is_expression_list* boolean;
	int codeline;
	int n_for;
	is_statement* inicial;
	is_statement* loop_stat;
	is_statement_list* list;

}is_for_stat;


/*is_statement ->is_write_stat V is_assgn_stat*/


/*is_vardec -> is_integer_dec V is_char_dec V is_double_dec*/

//Já existe o basic_type (na symbol_table.h)! Por isso, não é preciso criar um disc_vardec...

typedef struct _s4{
	basic_type disc_d;
	char* name;
	int codeline;
}is_vardec;


/*is_vardec_list*/
typedef struct _s3{
	struct _s3 *next;
	is_vardec *v;
}is_vardec_list;


/*main -> (<name:char*><vlist:is_vardec_list><slist:is_statement_list>)*/
typedef struct _s2b{
	char* name;
	is_vardec_list *vlist;
	is_statement_list *slist;
	is_args_vardec_list *avlist;
}is_procedure;



/*globals ->(<vlist:is_vardec_list>)*/

typedef struct _s2c{
	is_vardec_list *vlist;
}is_globals;

/*block*/
typedef enum {d_globals, d_procedure} disc_block;

typedef struct _s2{
	disc_block disc_d;
	union{
		is_globals* u_globals;
		is_procedure* u_procedure;
	}data_block;
}is_block;

/*is_block_list*/
typedef struct _s1{
	struct _s1 *next;
	is_block *p;
}is_block_list;




#endif
