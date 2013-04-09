%{
#include<stdio.h>
#include "sendHeader.h"
%}
%token RESERVED IF ELSE WHILE ATOI ITOA CHAR PRINTF RETURN EQ ASSIGN GE GT LE LT NE AMP AND AST
%token DIV COMMA SEMI LBRACE RBRACE LSQ RSQ LPAR RPAR MINUS PLUS MOD NOT OR INT

%%
statement: expression;

expression: IF{printf("IF");}
;


%%
int main()
{
	while(1){
		yyparse();
	}
	return 0;
}
