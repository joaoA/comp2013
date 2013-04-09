#include "structures.h"
#include <string.h>

is_assgn_stat* insert_assgn_stat_char(int line, char* var, char c);
is_block_list *insert_block_list(is_block_list* list, is_block *prog);
is_block* insert_procedure(char* name, is_args_vardec_list *alist,is_vardec_list* vlist, is_statement_list* slist);
is_block* insert_globals(is_vardec_list* vlist);
is_vardec_list *insert_vardec_list(is_vardec_list* list, is_vardec* v);
is_vardec *insert_vardec(int line, basic_type type, char* name);
is_statement_list* insert_statement_list(is_statement_list *list, is_statement *statement);
is_statement* insert_statement_write(is_write_stat* iws);
is_statement* insert_statement_assgn(is_assgn_stat* ias);
is_write_stat* insert_write_stat(int line, char* var);
is_statement* insert_statement_call(is_call_stat* ics);
is_call_stat* insert_call_stat(int line,char* var,is_call_arg_list *ical);
is_assgn_stat* insert_assgn_stat_boolean(int line, char *var, boolean b);
is_assgn_stat_2* update_variaveis(is_assgn_stat_2* variaveis, char* name,basic_type type);
is_if_stat* insert_if_stat(int line, is_expression_list* boolean, is_statement_list* list);
is_if_else_stat* insert_if_else_stat(int line, is_expression_list* boolean, is_statement_list* list,is_statement_list* list2,int n_if);
is_statement* insert_statement_if(is_if_stat* ifs);
is_statement* insert_statement_for(is_for_stat* ifs);
is_statement* insert_statement_if_else(is_if_else_stat* ifs);
is_while_stat* insert_while_stat(int line, is_expression_list* boolean, is_statement_list* list,int n_while);
is_statement* insert_statement_while(is_while_stat* iws);
is_expression* insert_expression(int line, char* cod, bol_type tipo);
is_assgn_stat* insert_assgn_stat_double(int line, char* var, is_expression_list* list);
is_assgn_stat* insert_assgn_stat_int(int line, char* var, is_expression_list* list);
is_expression_list *insert_expression_list(is_expression_list* list, is_expression* ex);
int is_int(char* name,is_assgn_stat_2* variaveis);
is_for_stat* insert_for_stat(int line, is_expression_list* boolean, is_statement_list* list,is_statement* inicial,is_statement* loop_stat,int n_for);
is_assgn_stat* insert_assgn_stat_read_int(int line, char* var);
is_assgn_stat* insert_assgn_stat_read_double(int line, char* var);
is_assgn_stat* insert_assgn_stat_read_char(int line, char* var);


is_return_statement* insert_return_stat(int line,char* name);
is_statement* insert_statement_return(is_return_statement* irs);

is_call_arg *insert_call_args_bool(boolean valor,basic_type type);
is_call_arg *insert_call_args_char(char valor,basic_type type);
is_call_arg *insert_call_args_doub(double valor,basic_type type);
is_call_arg *insert_call_args_int(int valor,basic_type type);
is_call_arg *insert_call_args_value(char *name);
is_call_arg_list *insert_call_agr_list(is_call_arg_list *ical,is_call_arg *ica);
is_args_vardec *insert_arg_vardec(int line,basic_type type, char *name);
is_args_vardec_list *insert_arg_vardec_list(is_args_vardec_list *iavl,is_args_vardec *iav);
is_write_stat *insert_write_stat_int(int line , int i);
is_write_stat *insert_write_stat_doub(int line , double d);
is_write_stat *insert_write_stat_char(int line , char c);
is_write_stat *insert_write_stat_bool(int line , boolean b);

