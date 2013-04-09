%{
#include<stdio.h>
#include "sendHeader.h"
%}
%token RESERVED IF ELSE WHILE ATOI ITOA CHAR PRINTF RETURN EQ ASSIGN GE GT LE LT NE AMP AND AST
%token DIV COMMA SEMI LBRACE RBRACE LSQ RSQ LPAR RPAR MINUS PLUS MOD NOT OR INT

%token<valorInteiro> INTLIT
%token<valorChar> CHRLIT
%token<valorString> STRLIT
%token<valorID> ID

%union{
	char* valorInteiro;
	char* valorChar;
	char* valorString;
	char* valorID;
}


%%
statement: expression;

expression: INTLIT {printf("INTLIT(%s)  linnha(%d) e coluna(%d)", $1,countLines,countColumns);}    //TODO[1] : se fizermos os atoi no lex isto estoira com numeros grandes....
		  | MINUS INTLIT {printf("NEG INTLIT(%s)", $2);} 
		  | CHRLIT {printf("CHRLIT(%s)", $1);}    //TODO[2] : verificar '\	'
		  | STRLIT {printf("STRLIT(%s)", $1);} 
		  | ID {printf("ID(%s)", $1);}    
		  ;


%%
int main()
{
	while(1){
		yyparse();
	}
	return 0;
}
