%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "semantic.h"

void show_table(table_element*);

is_block_list* myprog;
prog_env* prog_environment;
is_assgn_stat_2 *variaveis;

int n_while=0;
int n_if=0;
int n_for=0;
%}

%left SUM SUB
%left MULT DIV REST
%left OR
%left AND
%left NEG

%token FUNCTION INTEGER BOOLEAN DOUBLE CHARACTER DECLARE IN END GLOBAL CALL MAIN PRINT SEMI_COLON IF ELSE FOR WHILE READINT READDOUBLE
%token OPEN_BRACKET CLOSE_BRACKET COLON SUM SUB MULT DIV REST OR AND MENOR MAIOR DIFERENTE MAIORIGUAL MENORIGUAL ASSIGN IGUAL READCHAR
%token NOT RETURN

%token<id>IDENTIFIER
%token<valori>VALOR_INTEIRO
%token<character>VALOR_CHAR
%token<valord>VALOR_DOUBLE
%token<bool>VALOR_BOOLEAN
%type<ipl>block_list
%type<ip>block
%type<ivl>vardeclist
%type<iv>vardec
%type<isl>statement_list
%type<is>statement
%type<ics>call_stat 
%type<iws>print_stat
%type<ias>assgn_stat
%type<ifs>if_stat
%type<ifes>if_else_stat
%type<iwls>while_stat
%type<iex>expression
%type<iexl>expression_list
%type<ifrs>for_stat
%type<ica>call_args
%type<ical>call_argslist
%type<iav>args_vardec
%type<iavl>args_vardec_list
%type<irs>return_stat


%union{
char* id;
char* valord;
char* valori;
int inteiro;
char character;
double doub;
boolean bool;
is_block_list* ipl;
is_block* ip;
is_vardec_list* ivl;
is_vardec* iv;
is_statement_list* isl;
is_statement* is;
is_call_stat* ics;
is_write_stat* iws;
is_assgn_stat* ias;
is_if_stat* ifs;
is_for_stat* ifrs;
is_if_else_stat* ifes;
is_while_stat* iwls;
is_expression* iex;
is_expression_list* iexl;
is_call_arg *ica;
is_call_arg_list *ical;
is_args_vardec *iav;
is_args_vardec_list *iavl;
is_return_statement* irs;
}

%%
block_list:	block_list block		{$$=insert_block_list($1, $2);}
	|	block				{deleteAll(variaveis);variaveis = NULL;$$=insert_block_list(NULL, $1);
						myprog=$$;}
	;
block:	FUNCTION MAIN OPEN_BRACKET CLOSE_BRACKET COLON  vardeclist statement_list END  		{$$=insert_procedure("main",NULL, $6, $7);}
	|FUNCTION IDENTIFIER OPEN_BRACKET args_vardec_list CLOSE_BRACKET COLON  vardeclist statement_list END  	{$$=insert_procedure($2,$4, $7, $8);}
	| GLOBAL vardeclist	END					{$$=insert_globals($2);}
	;

args_vardec_list:	/*empty*/{$$=NULL;} 
	|	args_vardec_list args_vardec  {$$=insert_arg_vardec_list($1,$2);}
	;

args_vardec:	INTEGER IDENTIFIER	{$$=insert_arg_vardec(line,integer,$2);}
	|	CHARACTER IDENTIFIER	{$$=insert_arg_vardec(line,character,$2);}
	|	DOUBLE IDENTIFIER	{$$=insert_arg_vardec(line,doub,$2);}
	|	BOOLEAN IDENTIFIER	{$$=insert_arg_vardec(line,bool,$2);}
	;


vardeclist:	/*empty*/			{$$=NULL;}
		| vardeclist vardec   		{$$=insert_vardec_list($1, $2);}
		;
	
vardec:	 INTEGER IDENTIFIER SEMI_COLON		{variaveis=update_variaveis(variaveis,$2,integer);$$=insert_vardec(line, integer, $2);}	
	| CHARACTER IDENTIFIER SEMI_COLON	{$$=insert_vardec(line, character, $2);} 
	| DOUBLE IDENTIFIER SEMI_COLON		{variaveis=update_variaveis(variaveis,$2,doub);$$=insert_vardec(line, doub, $2);}
	| BOOLEAN IDENTIFIER SEMI_COLON		{$$=insert_vardec(line, bool, $2);}
	;

statement_list: /*empty*/			{$$=NULL;}
	        |statement_list statement 	{$$=insert_statement_list($1, $2);}
		;

statement: 	print_stat 			{$$=insert_statement_write($1);}
	|	assgn_stat 			{$$=insert_statement_assgn($1);}
	|	call_stat 			{$$=insert_statement_call($1);}
	|	if_else_stat 			{$$=insert_statement_if_else($1);}
	|	if_stat				{$$=insert_statement_if($1);}
	|	while_stat			{$$=insert_statement_while($1);}
	|	for_stat			{$$=insert_statement_for($1);}
	|	return_stat			{$$=insert_statement_return($1);}
	;

return_stat:	RETURN IDENTIFIER SEMI_COLON	{$$=insert_return_stat(line,$2);}
	;

for_stat:	FOR OPEN_BRACKET statement expression_list SEMI_COLON statement CLOSE_BRACKET COLON statement_list END{$$=insert_for_stat(line,$4,$9,$3,$6,n_for);n_for++;}
	;


while_stat:	WHILE OPEN_BRACKET expression_list CLOSE_BRACKET COLON statement_list END	{$$=insert_while_stat(line, $3,$6,n_while);n_while++;}
	;

if_stat: 	IF OPEN_BRACKET expression_list CLOSE_BRACKET COLON statement_list END{$$=insert_if_stat(line, $3, $6);}
	;

if_else_stat: 	IF OPEN_BRACKET expression_list CLOSE_BRACKET COLON statement_list ELSE COLON statement_list END{$$=insert_if_else_stat(line, $3, $6,$9,n_if);n_if++;}
	;

call_argslist:	/*empty*/			{$$=NULL;}
	|	call_argslist call_args		{$$=insert_call_agr_list($1,$2);}
	;

call_args:	IDENTIFIER			{$$=insert_call_args_value($1);}
	|	VALOR_INTEIRO			{$$=insert_call_args_int(atoi($1),integer);}
	|	VALOR_DOUBLE			{$$=insert_call_args_doub(atof($1),doub);}
	|	VALOR_CHAR			{$$=insert_call_args_char($1,character);}
	|	VALOR_BOOLEAN			{$$=insert_call_args_bool($1,bool);}
	;


call_stat:	CALL IDENTIFIER OPEN_BRACKET call_argslist  CLOSE_BRACKET SEMI_COLON	{$$=insert_call_stat(line, $2,$4);}
	;

print_stat:	PRINT IDENTIFIER SEMI_COLON		{$$=insert_write_stat(line, $2);}
	|	PRINT VALOR_INTEIRO SEMI_COLON		{$$=insert_write_stat_int(line, atoi($2));}
	|	PRINT VALOR_DOUBLE SEMI_COLON		{$$=insert_write_stat_doub(line, atof($2));}
	|	PRINT VALOR_CHAR SEMI_COLON		{$$=insert_write_stat_char(line, $2);}
	|	PRINT VALOR_BOOLEAN SEMI_COLON		{$$=insert_write_stat_bool(line, $2);}
	;


assgn_stat:	IDENTIFIER ASSIGN VALOR_CHAR SEMI_COLON		{$$=insert_assgn_stat_char(line, $1, $3);}
	| 	IDENTIFIER ASSIGN expression_list SEMI_COLON	{if(is_int($1,variaveis)!=1){ $$=insert_assgn_stat_double(line, $1, $3);}else{ $$=insert_assgn_stat_int(line, $1, $3);}}
	|	IDENTIFIER ASSIGN VALOR_BOOLEAN	SEMI_COLON	{$$=insert_assgn_stat_boolean(line,$1,$3);}
	| 	IDENTIFIER ASSIGN READINT SEMI_COLON		{$$=insert_assgn_stat_read_int(line,$1);}
	| 	IDENTIFIER ASSIGN READDOUBLE SEMI_COLON		{$$=insert_assgn_stat_read_double(line,$1);}
	| 	IDENTIFIER ASSIGN READCHAR SEMI_COLON		{$$=insert_assgn_stat_read_char(line,$1);}
	;

expression_list:/*empty*/							{$$=NULL;}
	|	expression_list expression					{$$=insert_expression_list($1,$2);}
	;

expression: VALOR_INTEIRO	{$$=insert_expression(line,$1,not_var);}
	|	VALOR_DOUBLE	{$$=insert_expression(line,$1,not_var);}
	|	SUM		{$$=insert_expression(line,"+",not_var);}
	|	DIV		{$$=insert_expression(line,"/",not_var);}
	|	MULT		{$$=insert_expression(line,"*",not_var);}
	|	REST		{$$=insert_expression(line,"%",not_var);}
	|	OR		{$$=insert_expression(line,"|",not_var);}
	|	AND		{$$=insert_expression(line,"&",not_var);}
	|	OPEN_BRACKET	{$$=insert_expression(line,"(",not_var);}
	|	CLOSE_BRACKET	{$$=insert_expression(line,")",not_var);}
	|	SUB		{$$=insert_expression(line,"-",not_var);}
	|	IDENTIFIER	{$$=insert_expression(line,$1,var);}
	|	MAIOR		{$$=insert_expression(line,">",not_var);}
	| 	MAIORIGUAL	{$$=insert_expression(line,">=",not_var);}
	|	MENOR		{$$=insert_expression(line,"<",not_var);}
	|	MENORIGUAL	{$$=insert_expression(line,"<=",not_var);}
	|	IGUAL		{$$=insert_expression(line,"==",not_var);}
	|	DIFERENTE	{$$=insert_expression(line,"!=",not_var);}
	|	NOT		{$$=insert_expression(line,"!",not_var);}
	;


%%
int main(int argc, char **argv)
{
int parsingOK;

line=1;

parsingOK=yyparse();

if(parsingOK==0)  //S� faz an�lise sem�ntica se n�o houve problemas de sintaxe
{
	prog_environment=semantic_analysis(myprog);

	printf("Your program has %d errors\n", erros);

	if(erros==0)
	{
		translate(myprog, prog_environment);
//		show_block_list(myprog);
//		show_table(prog_environment->global);
	}
}
return 0;
}

int yyerror(char *msg)
{
printf("line %d: %s\n", line, msg);

return 1;
}


void show_table(table_element* table)
{
	table_element *aux;
	printf("\n");

	for(aux=table; aux; aux=aux->next){
		printf("symbol %s, type %s\n", aux->name, typeToString(aux->type));
	}
}

