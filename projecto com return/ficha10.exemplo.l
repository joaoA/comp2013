%{
#include "structures.h"
#include "y.tab.h"
#include <string.h>
%}
ID       [a-z][a-z0-9]*
numero	 [0-9]+
float	 [0-9]+("."[0-9]+)
char	 '[A-Za-z]'
open_bracket [(]
close_bracket [)]
colon	[:]	
sum	[+]
sub	[-]
mult	[*]
div	[/]
rest	[%]
or	['|']
and	[&]
assgn	[=]
maior	[>]
menor	[<]
not	[!]
igual	("==")
maiorigual	(">=")
menorigual	("<=")
diferente	("!=")
semi_colon	[;]
readint		("readInt()")
readdouble	("readDouble()")
readchar	("readChar()")
return		("return")
%%
{return}		{return RETURN;}
{not}			{return NOT;}
{readint}		{return READINT;}
{readdouble}		{return READDOUBLE;}
{readchar}		{return READCHAR;}
("true"|"false")		{if(strcmp(yytext,"true")==0) yylval.bool=true;else yylval.bool=false;return VALOR_BOOLEAN;}

{numero}		{yylval.valori=(char *) strdup(yytext);
			return VALOR_INTEIRO;}

{float}			{yylval.valord=(char *) strdup(yytext);
			return VALOR_DOUBLE;}

{char}			{yylval.character=yytext[1];
			return VALOR_CHAR;}
{maior}			{return MAIOR;}

{menor}			{return MENOR;}

{igual}			{return IGUAL;}

{maiorigual}		{return MAIORIGUAL;}

{menorigual}		{return MENORIGUAL;}

{diferente}		{return DIFERENTE;}

int	 		{return INTEGER;}

double   		{return DOUBLE;}

char     		{return CHARACTER;}

boolean			{return BOOLEAN;}

global			{return GLOBAL;}

declare      		{return(DECLARE);}

in	 		{return IN;}

end	 		{return END;}

print    		{return PRINT;}

function 		{return FUNCTION;}

main			{return MAIN;}

{assgn}			{return ASSIGN;}

{open_bracket}		{return OPEN_BRACKET;}

{close_bracket}		{return CLOSE_BRACKET;}	;

{colon}			{return COLON;}

{sum}                   {return SUM;}

{sub}                   {return SUB;}

{mult}                  {return MULT;}

{div}                   {return DIV;}

{rest}			{return REST;}

{semi_colon}		{return SEMI_COLON;}

{or}			{return OR;}

{and}			{return AND;}

call	 		{return CALL;}

if			{return IF;}

else			{return ELSE;}

for			{return FOR;}

while			{return WHILE;}

{ID}     		{yylval.id = (char *) strdup(yytext); 
 	                return(IDENTIFIER);}

[ \t]+ 			{;}

\n	 		{line++;}
.        		{return(yytext[0]);}

%%
int yywrap(void){}

