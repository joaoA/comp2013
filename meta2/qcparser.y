%{
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"
#include "shows.h"

extern int countLines;
extern int countColumns;
extern int yyleng;
extern char* yytext;

void yyerror (char *s);
int yylex(void);

is_node *myProgram;

%}
%token RESERVED IF ELSE WHILE ATOI ITOA CHAR PRINTF RETURN EQ ASSIGN GE GT LE LT NE AMP AND AST
%token DIV COMMA SEMI LBRACE RBRACE LSQ RSQ LPAR RPAR MINUS PLUS MOD NOT OR INT

%token <valorInteiro> INTLIT
%token <valorChar> CHRLIT
%token <valorString> STRLIT
%token <valorID> ID

%type <node> expression new_one new_two new_four statement new_six new_seven declarator declaration typeSpecifier new_eight parameterDeclaration new_nine parameterList new_ten functionDeclarator functionDeclaration functionDefinition start new_eleven 

%union{
	int valorInteiro;
	char* valorChar;
	char* valorString;
	char* valorID;
	is_node *node;
}

%left COMMA
%right ASSIGN
%left OR
%left AND
%left AMP
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left AST DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ LBRACE RBRACE
%nonassoc ELSE 

%%
start: 		start functionDefinition    {$$=insert_link($1, $2);}
		|	start functionDeclaration 	{$$=insert_link($1, $2);}
		| 	start declaration           {$$=insert_link($1, $2);}
		|   functionDefinition          {$$=$1; myProgram=$$;} 
		|   functionDeclaration  		{$$=$1; myProgram=$$;}
		|   declaration 				{$$=$1; myProgram=$$;}
		;


functionDefinition: typeSpecifier functionDeclarator LBRACE new_eleven new_four RBRACE 	{$$=insert_function_definition(d_func_definition, $1, $2, $4, $5);}
		;

new_eleven: new_eleven declaration  						{$$=insert_nulls($1, $2);}
		| 													{$$=insert_token(d_null);}
		;

functionDeclaration: typeSpecifier functionDeclarator SEMI	{$$=insert_function_declaration(d_func_declaration, $1, $2);}
		;

functionDeclarator: new_six ID LPAR new_ten RPAR			{$$=insert_function_declarator(d_func_declarator, $1, insert_string(d_id, $2), $4);}
		;

new_ten: parameterList 										{$$=$1;}
		|													{$$=insert_token(d_null);}
		;

parameterList: parameterDeclaration new_nine				{$$=insert_param_list(d_param_list, $1, $2);}
		;

new_nine: new_nine COMMA parameterDeclaration 				{$$=insert_nulls($1, $3);}
		|													{$$=insert_token(d_null);}
		;

parameterDeclaration: typeSpecifier new_six ID 				{$$=insert_param_declaration(d_param_declaration, $1, $2, insert_string(d_id, $3));}
		;

declaration: typeSpecifier declarator new_eight SEMI		{$$=insert_declaration(d_declaration, $1,$2, $3);}
		;

new_eight: new_eight COMMA declarator 						{$$=insert_nulls($1, $3);}
		|													{$$=insert_token(d_null);}
		;

typeSpecifier: INT 					{$$=insert_token(d_int);}
		|	CHAR 					{$$=insert_token(d_char);}
		;

declarator: new_six ID new_seven	{
										if($3==NULL){
											$$=insert_declarator(d_declarator, $1, insert_string(d_id, $2), $3);
										} else {
											$$=insert_declarator(d_array_declarator, $1, insert_string(d_id, $2), $3);
										}

									}
		;

new_six: new_six AST				{$$=insert_nulls($1, insert_token(d_pointer));}
		|							{$$=insert_token(d_null);}
		;

new_seven: LSQ expression RSQ		{$$=$2;}
		| 							{$$=insert_token(d_null);}
		;

statement: SEMI													{;}					
		|	expression SEMI										{$$=$1;}
		|	LBRACE new_four RBRACE								{$$=$2;}
		|	IF LPAR expression RPAR statement 					{$$=insert_if(d_if, $3, $5);}
		|	IF LPAR expression RPAR statement ELSE statement	{$$=insert_if_else(d_if_else, $3, $5, $7);}
		|	WHILE LPAR expression RPAR statement				{$$=insert_while(d_while, $3, $5);}
		|	RETURN expression SEMI								{$$=insert_return(d_return, $2);}
		;

new_four: new_four statement									{$$=insert_nulls($1, $2);}
		|														{$$=insert_token(d_null);}
		;

expression: expression ASSIGN expression 					{$$=insert_infix_expression(d_store, $1, $3);}
		|	expression OR expression 						{$$=insert_infix_expression(d_or, $1, $3);}
		|	expression AND expression 						{$$=insert_infix_expression(d_and, $1, $3);}
		|	expression GE expression 						{$$=insert_infix_expression(d_ge, $1, $3);}
		|	expression LE expression 						{$$=insert_infix_expression(d_le, $1, $3);}
		|	expression GT expression 						{$$=insert_infix_expression(d_gt, $1, $3);}
		|	expression LT expression 						{$$=insert_infix_expression(d_lt, $1, $3);}
		|	expression NE expression 						{$$=insert_infix_expression(d_ne, $1, $3);}
		|	expression EQ expression 						{$$=insert_infix_expression(d_eq, $1, $3);}
		|	expression MOD expression 						{$$=insert_infix_expression(d_mod, $1, $3);}
		|	expression DIV expression  						{$$=insert_infix_expression(d_div, $1, $3);}
		|	expression AST expression       				{$$=insert_infix_expression(d_mul, $1, $3);}
		|	expression MINUS expression 					{$$=insert_infix_expression(d_minus, $1, $3);}
		|	expression PLUS expression   					{$$=insert_infix_expression(d_plus, $1, $3);}
		|	NOT expression 									{$$=insert_unary_expression(d_not, $2);}
		|	MINUS expression 								{$$=insert_unary_expression(d_minus, $2);}
		|	PLUS expression 								{$$=insert_unary_expression(d_plus, $2);}
		|	AST expression 									{$$=insert_unary_expression(d_pointer, $2);}
		|	AMP expression 									{$$=insert_unary_expression(d_addr, $2);}
		|	expression LSQ expression RSQ					{$$=insert_infix_expression(d_deref, $1, $3);}
		|	ID LPAR new_one RPAR							{$$=insert_link(insert_string(d_id, yytext), $3);}
		|	ATOI LPAR expression RPAR 						{$$=insert_atoi(d_atoi, $3);}
		|	PRINTF LPAR expression RPAR						{$$=insert_printf(d_print, $3);}
		| 	ITOA LPAR expression COMMA expression RPAR		{$$=insert_itoa(d_itoa, $3, $5);}
		|	LPAR expression RPAR							{$$=$2;}
		|	STRLIT											{$$=insert_string(d_strlit, $1);}
		|	CHRLIT											{$$=insert_string(d_charlit, $1);}
		|	INTLIT											{$$=insert_number(d_intlit, $1);}
		|	ID 												{$$=insert_string(d_id, $1);}
		  ;

new_one: expression new_two									{$$=insert_nulls($1, $2);}
		|													{$$=insert_token(d_null);}
		;

new_two: new_two COMMA expression							{$$=insert_nulls($1, $3);}
		|													{$$=insert_token(d_null);}
		;

%%
int main()
{
	yyparse();
	show_program(myProgram);
	return 0;
}

void yyerror (char *s) {

	countColumns -= yyleng;

	if(strcmp(yytext, "") == 0){
		countColumns++;
	}
	printf("Line %d, col %d: %s: %s\n", countLines, countColumns, s, yytext);
	
}

