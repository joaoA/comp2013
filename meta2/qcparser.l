%x COMMENT CHARACTER CHARACTER_ESCAPE STRING STRING_ESCAPE

%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <ctype.h>
	#include "sendHeader.h"
	#include "y.tab.h"

	int validationIntLit(char* text);

	char c,d;
	int countChars = 0;
	int aux_comments [2] = {1,1};
	char character[30];
	char string[500];



%}
COMBEG		"/*"		
COMEND		"*/"

KEYWORDS 	auto|break|case|const|continue|default|do|double|enum|extern|float|for|goto|long|register|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|"++"|"--"

ID				[a-zA-Z_]([a-zA-Z0-9_])*
INTLIT			([1-9][0-9]*)|0


%%
{KEYWORDS}				{countColumns +=yyleng; return RESERVED;}

{COMBEG}				{
							BEGIN COMMENT;
							aux_comments[0] = countLines;
							aux_comments[1] = countColumns;
							countColumns +=yyleng;
						}

<COMMENT>\n				{
							countLines++; 
							countColumns=1;
						}

<COMMENT>{COMEND}		{
							BEGIN(INITIAL);
							countColumns +=yyleng;
						}	

<COMMENT>.		{countColumns +=yyleng;}	

<COMMENT><<EOF>>		{
							printf("Line %d, col %d: unterminated comment\n",aux_comments[0],aux_comments[1]); 
							BEGIN 0;
							countColumns += yyleng;
						}

"'"					{
						BEGIN CHARACTER;
						aux_comments[0] = countLines;
						aux_comments[1] = countColumns;
						countColumns += yyleng;
						countChars = 0;
						strcpy(character, "");
					}

<CHARACTER>\n 		{
						countColumns = 1;
						countLines++;
						printf("Line %d, col %d: unterminated char constant\n", aux_comments[0], aux_comments[1]);
						BEGIN (INITIAL);
					}

<CHARACTER>"\\"		{	
						BEGIN CHARACTER_ESCAPE;
						countColumns +=yyleng;
						if(countChars==0){
							countChars = 0;
						} else {
							countChars = 2;
						}
						strcat(character, yytext);
					}

<CHARACTER_ESCAPE>\n {
						BEGIN 0; 
						countColumns = 1;
						countLines++;
						printf("Line %d, col %d: unterminated char constant\n", aux_comments[0], aux_comments[1]);
						BEGIN (INITIAL);
					}

<CHARACTER_ESCAPE>.	{
						BEGIN CHARACTER;
						countColumns +=yyleng;
						countChars++;
						strcat(character, yytext);
					}		

<CHARACTER>"'"		{
						countColumns += yyleng;
						BEGIN(INITIAL);
						if(countChars == 1){
							yylval.valorChar=character;
							return CHRLIT;
						} else {
							printf("Line %d, col %d: multi-character char constant\n", aux_comments[0], aux_comments[1]);
						}
					}

<CHARACTER>.?		{
						countColumns +=yyleng;
						strcat(character, yytext);
						countChars++;
					}

"\""				{
						BEGIN STRING;
						aux_comments[0] = countLines;
						aux_comments[1] = countColumns;
						countColumns += yyleng;
						countChars = 0;
						strcpy(string, "");	
					}

<STRING>\n			{
						BEGIN (INITIAL);
						countColumns = 1;
						countLines++;
						printf("Line %d, col %d: unterminated string constant\n", aux_comments[0], aux_comments[1]);
					}

<STRING>"\\"		{	
						BEGIN STRING_ESCAPE;
						countColumns +=yyleng;
						strcat(string, yytext);
					}

<STRING_ESCAPE>\n {
						BEGIN 0; 
						countColumns = 1;
						countLines++;
						printf("Line %d, col %d: unterminated string constant\n", aux_comments[0], aux_comments[1]);
						BEGIN (INITIAL);
					}

<STRING_ESCAPE>.	{
						BEGIN STRING;
						countColumns +=yyleng;
						strcat(string, yytext);
					}

<STRING>"\""		{
						BEGIN (INITIAL);
						countColumns += yyleng;
						yylval.valorString=string;
						return STRLIT;
					}

<STRING>.			{
						countColumns +=yyleng;
						strcat(string, yytext);	
					}


"if"				{countColumns +=yyleng; return IF;}
"else"				{countColumns +=yyleng; return ELSE;}
"while"				{countColumns +=yyleng; return WHILE;}

"atoi"				{countColumns +=yyleng; return ATOI;}
"itoa"				{countColumns +=yyleng; return ITOA;}

"char"				{countColumns +=yyleng; return CHAR;}
"int"				{countColumns +=yyleng; return INT;}

"printf"			{countColumns +=yyleng; return PRINTF;}
"return"			{countColumns +=yyleng; return RETURN;}


"=="    			{countColumns +=yyleng; return EQ;}
"="    				{countColumns +=yyleng; return ASSIGN;}
">="    			{countColumns +=yyleng; return GE;}
">"    				{countColumns +=yyleng; return GT;}
"<="    			{countColumns +=yyleng; return LE;}
"<"    				{countColumns +=yyleng; return LT;}
"!="    			{countColumns +=yyleng; return NE;}

"&"    				{countColumns +=yyleng; return AMP;}
"&&"    			{countColumns +=yyleng; return AND;}

"*"    				{countColumns +=yyleng; return AST;}

"/"    				{countColumns +=yyleng; return DIV;}
","    				{countColumns +=yyleng; return COMMA;}
";"    				{countColumns +=yyleng; return SEMI;}

"{"    				{countColumns +=yyleng; return LBRACE;}
"}"    				{countColumns +=yyleng; return RBRACE;}
"["    				{countColumns +=yyleng; return LSQ;}
"]"    				{countColumns +=yyleng; return RSQ;}
"("    				{countColumns +=yyleng; return LPAR;}
")"    				{countColumns +=yyleng; return RPAR;}

"-"    				{countColumns +=yyleng; return MINUS;}
"+"    				{countColumns +=yyleng; return PLUS;}
"%"    				{countColumns +=yyleng; return MOD;}
"!"    				{countColumns +=yyleng; return NOT;}
"||"    			{countColumns +=yyleng; return OR;}




{INTLIT}			{countColumns +=yyleng; yylval.valorInteiro=(char *) strdup(yytext);
					return INTLIT;}
{ID}				{countColumns +=yyleng;yylval.valorInteiro=(char *) strdup(yytext);
					return ID;}




[ \t]+ 				{; countColumns +=yyleng;}
\n 					{
						countLines++; 
						countColumns=1;
					}
.	{
		printf("Line %d, col %d: illegal character ('%s')\n", countLines, countColumns, yytext);
		countColumns +=yyleng;
	}

%%

int yywrap()
{
return 1;
}
