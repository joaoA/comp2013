#include "structures.h"
#include "symbol_table.h"
int erros;


prog_env* semantic_analysis(is_block_list* ipl);
void semantic_analysis_block(prog_env *pe, is_block* ip,is_block_list *ibl);
void semantic_analysis_procedure(prog_env *pe, is_procedure* ipr,is_block_list *ibl);
void semantic_analysis_globals(prog_env *pe, is_globals* ipg);
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_vardec_list* ivl);
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_vardec* iv);
void semantic_analysis_statement_list(prog_env *pe, table_element* local, is_statement_list* isl,char *name,is_block_list *ibl);
void semantic_analysis_statement(prog_env *pe,  table_element* local, is_statement* is,char *name,is_block_list *ibl);
void semantic_analysis_write_stat(prog_env *pe,  table_element* local, is_write_stat* iws);
void semantic_analysis_assgn_stat(prog_env *pe,  table_element* local,is_assgn_stat* ias);
is_args_vardec_list * semantic_analysis_call_stat(prog_env *pe,char *name,table_element* local,is_call_stat* ics,is_block_list *ibl);
char* typeToString(int type);
table_element* create_symbol(int offset, char* name, basic_type type,int isArg);
table_element *lookup(table_element* table, char *str);
environment_list *plookup(environment_list* procs, char* procname);


table_element *semantic_analysis_argvardec(int offset, prog_env* pe, table_element* stable, is_args_vardec* iav);
table_element *semantic_analysis_argvardeclist(int scope, prog_env *pe, table_element* stable, is_args_vardec_list* iavl);
