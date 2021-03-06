/*
Autor: Francisco Pereira

Disclaimer: Este e' um ficheiro de exemplo de alguns conceitos falados nas fichas 9 e 10. Note-se que sao APENAS EXEMPLOS. Nao deverao ser 
tomados como dogmas. Repare-se que, caso se tratasse de um compilador de LYSP, haveriam imensas coisas a mudar!!
O que se pretende e' que o aluno esclareca algumas duvidas, nao que assuma uma filosofica de copy+paste sobre  este codigo.
*/


#include "structures.h"
#include "symbol_table.h"
#include <stdio.h>

void translate(is_block_list* list, prog_env* pe);
void translate_header(FILE* dest);
void translate_footer(FILE* dest);
void translate_block_list(FILE* dest, is_block_list* ipl, prog_env* pe);
void translate_block(FILE* dest, is_block* ip, environment_list* etmp, prog_env* pe);
void translate_global_list(FILE* dest, prog_env* pe);
void translate_global_vardec(FILE* dest, basic_type type, int offset);
void translate_main(FILE* dest, is_procedure* main, environment_list* local, prog_env* pe);
void translate_vardecs(FILE* dest, is_vardec_list* ivl, environment_list* local, prog_env* pe);
void translate_vardec(FILE* dest, is_vardec* iv, environment_list* local, prog_env* pe);
void translate_statements(FILE* dest, is_statement_list* isl, environment_list* local,char* nameProc, prog_env* pe);
void translate_statement(FILE* dest, is_statement* is, environment_list* local,char* nameProc, prog_env* pe);
void translate_write_stat(FILE* dest, is_write_stat* iws, environment_list* local, prog_env* pe);
void translate_assgn_stat(FILE* dest, is_assgn_stat* ias, environment_list* local, prog_env* pe);
void translate_call_stat(FILE* dest, is_call_stat* ias, prog_env* pe);
void translate_procedure(FILE* dest, is_procedure* ip, prog_env* pe);
void translate_redirector(FILE* dest);
void translate_if_stat(FILE* dest, is_if_stat* ifs, environment_list* local, char *nameProc ,prog_env* pe);
void translate_if_else_stat(FILE* dest, is_if_else_stat* ifs, environment_list* local,char *nameProc , prog_env* pe);
void translate_while_stat(FILE* dest, is_while_stat* ifs, environment_list* local,char *nameProc , prog_env* pe);
void print_assgn(FILE* dest, is_assgn_stat* ias, environment_list* local, prog_env* pe,table_element* t);
void translate_for_stat(FILE* dest, is_for_stat* ifs, environment_list* local,char *nameProc , prog_env* pe);

void translate_return_stat(FILE* dest, is_return_statement* irs, environment_list* local,char* nameProc, prog_env* pe);

void print_args_vardec(FILE* dest, is_args_vardec* ias, environment_list* local, prog_env* pe,table_element* t);
void translate_args_vardecs(FILE* dest, is_args_vardec_list* ivl, environment_list* local, prog_env* pe);
void translate_args_vardec(FILE* dest, is_args_vardec* iav,  environment_list* local, prog_env* pe);

