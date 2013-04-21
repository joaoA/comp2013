%{
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"

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

%type <node> expression new_one new_two

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
start: functionDefinition new_twelve
		|	functionDeclaration new_twelve
		| 	declaration new_twelve
		;

new_twelve: new_twelve functionDefinition
		|	new_twelve functionDeclaration
		|	new_twelve declaration
		| 
		;

functionDefinition: typeSpecifier functionDeclarator LBRACE new_eleven new_four RBRACE
		;

new_eleven: new_eleven declaration
		|
		;

functionDeclaration: typeSpecifier functionDeclarator SEMI
		;

functionDeclarator: new_six ID LPAR new_ten RPAR
		;

new_ten: parameterList
		|
		;

parameterList: parameterDeclaration new_nine
		;

new_nine: new_nine COMMA parameterDeclaration
		|
		;

parameterDeclaration: typeSpecifier new_six ID
		;

declaration: typeSpecifier declarator new_eight SEMI
		;

new_eight: new_eight COMMA declarator
		|
		;

typeSpecifier: INT
		|	CHAR
		;

declarator: new_six ID new_seven
		;

new_six: new_six AST
		|
		;

new_seven: LSQ expression RSQ
		|
		;

statement: new_five SEMI
		|	LBRACE new_four RBRACE
		|	IF LPAR expression RPAR statement 
		|	IF LPAR expression RPAR statement ELSE statement
		|	WHILE LPAR expression RPAR statement				{$$=insert_while(d_while, $3, $5);}
		|	RETURN expression SEMI								{$$=insert_return(d_return, $2);}
		;

new_four: new_four statement
		|
		;

new_five: expression
		|
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
		|	AST expression 									{$$=insert_unary_expression(d_mul, $2);}
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

new_one: expression new_two									{$$=insert_link($1, $2);}
		|													{$$=insert_token(d_null);}
		;

new_two: new_two COMMA expression							{$$=insert_link($1, $3);}
		|													{$$=insert_token(d_null);}
		;

%%
int main()
{
	yyparse();
	
	return 0;
}

void yyerror (char *s) {

	countColumns -= yyleng;

	if(strcmp(yytext, "") == 0){
		countColumns++;
	}
	printf("Line %d, col %d: %s: %s\n", countLines, countColumns, s, yytext);
	
}

