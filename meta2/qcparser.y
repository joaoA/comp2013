%{
	
#include<stdio.h>

#include "structures.h"

extern int countLines;
extern int countColumns;
extern int yyleng;
extern char* yytext;

void yyerror (char *s);

%}
%token RESERVED IF ELSE WHILE ATOI ITOA CHAR PRINTF RETURN EQ ASSIGN GE GT LE LT NE AMP AND AST
%token DIV COMMA SEMI LBRACE RBRACE LSQ RSQ LPAR RPAR MINUS PLUS MOD NOT OR INT

%token INTLIT
%token CHRLIT
%token STRLIT
%token ID

%union{
	char* valorInteiro;
	char* valorChar;
	char* valorString;
	char* valorID;
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
		|	WHILE LPAR expression RPAR statement
		|	RETURN expression SEMI
		;

new_four: new_four statement
		|
		;

new_five: expression
		|
		;

expression: expression ASSIGN expression
		|	expression OR expression
		|	expression AND expression
		|	expression GE expression
		|	expression LE expression
		|	expression GT expression
		|	expression LT expression
		|	expression NE expression
		|	expression EQ expression
		|	expression MOD expression
		|	expression DIV expression
		|	expression AST expression
		|	expression MINUS expression
		|	expression PLUS expression
		|	NOT expression
		|	MINUS expression
		|	PLUS expression
		|	AST expression
		|	AMP expression
		|	expression LSQ expression RSQ
		|	ID LPAR new_one RPAR
		|	ATOI LPAR expression RPAR 
		|	PRINTF LPAR expression RPAR
		| 	ITOA LPAR expression COMMA expression RPAR
		|	LPAR expression RPAR
		|	STRLIT
		|	CHRLIT
		|	INTLIT
		|	ID
		  ;

new_one: expression new_two
		|
		;

new_two: new_two COMMA expression
		|
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

