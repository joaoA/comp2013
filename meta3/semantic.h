#include "structures.h"
#include "symbol_table.h"

prog_env* semantic_analysis(is_node* myProgram);
void semantic_analysis_block(prog_env *pe, is_node* ip);
void semantic_analysis_globals(prog_env *pe, is_node* ipg);
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_node* ivl);
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_node* iv, disc_node type);
table_element *lookup(table_element* table, char *str);
table_element* create_symbol(int offset, is_node* node, disc_node type);
void semantic_analysis_procedures(prog_env *pe, is_node* ipg);
param_data* semantic_analysis_create_param_data(prog_env* pe, is_node* pi, param_data* params);
param_data* create_param(is_node* pip);
table_element* semantic_analysis_create_locals_list(int scope, prog_env* pe, is_node* ip, table_element* locals);
table_element* semantic_analysis_create_locals(int offset, is_node* ip, table_element* locals);
