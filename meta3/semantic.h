#include "structures.h"
#include "symbol_table.h"

prog_env* semantic_analysis(is_node* myProgram);
void semantic_analysis_block(prog_env *pe, is_node* ip);
void semantic_analysis_globals(prog_env *pe, is_node* ipg);
table_element* semantic_analysis_vardeclist(int scope, prog_env *pe, table_element* stable, is_node* ivl);
table_element* semantic_analysis_vardec(int offset, prog_env* pe, table_element* stable, is_node* iv, disc_node type);
table_element *lookup(table_element* table, char *str);
table_element* create_symbol(int offset, is_node* node, disc_node type);