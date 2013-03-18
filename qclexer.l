%x COMMENT CHARACTER CHARACTER_ESCAPE STRING STRING_ESCAPE

%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <ctype.h>

	int validationIntLit(char* text);

	char c,d;
	int countLines=1, countColumns=1, countChars = 0;
	int aux_comments [2] = {1,1};
	char character[30];
	char string[500];


%}
COMBEG		"/*"		
COMEND		"*/"

KEYWORDS 	auto|break|case|const|continue|default|do|double|enum|extern|float|for|goto|long|register|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile

ID				[a-zA-Z_]([a-zA-Z0-9_])*
INTLIT			([1-9][0-9]*)|0


%%
{KEYWORDS}				{printf("RESERVED\n"); countColumns +=yyleng;}

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

<COMMENT>[^{COMEND}]		{countColumns +=yyleng;}	
<COMMENT>{COMEND}		{
							BEGIN(INITIAL);
							countColumns +=yyleng;
						}	

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
							printf("CHRLIT('%s')\n", character);
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
						printf("STRLIT(\"%s\")\n", string);
					}

<STRING>.			{
						countColumns +=yyleng;
						strcat(string, yytext);	
					}


"if"				{printf("IF\n"); countColumns +=yyleng;}
"else"				{printf("ELSE\n"); countColumns +=yyleng;}
"while"				{printf("WHILE\n"); countColumns +=yyleng;}

"atoi"				{printf("ATOI\n"); countColumns +=yyleng;}
"itoa"				{printf("ITOA\n"); countColumns +=yyleng;}

"char"				{printf("CHAR\n"); countColumns +=yyleng;}
"int"				{printf("INT\n"); countColumns +=yyleng;}

"printf"			{printf("PRINTF\n"); countColumns +=yyleng;}
"return"			{printf("RETURN\n"); countColumns +=yyleng;}


"=="    			{printf("EQ\n"); countColumns +=yyleng;}
"="    				{printf("ASSIGN\n"); countColumns +=yyleng;}
">="    			{printf("GE\n"); countColumns +=yyleng;}
">"    				{printf("GT\n"); countColumns +=yyleng;}
"<="    			{printf("LE\n"); countColumns +=yyleng;}
"<"    				{printf("LT\n"); countColumns +=yyleng;}
"!="    			{printf("NE\n"); countColumns +=yyleng;}

"&"    				{printf("AMP\n"); countColumns +=yyleng;}
"&&"    			{printf("AND\n"); countColumns +=yyleng;}

"*"    				{printf("AST\n"); countColumns +=yyleng;}

"/"    				{printf("DIV\n"); countColumns +=yyleng;}
","    				{printf("COMMA\n"); countColumns +=yyleng;}
";"    				{printf("SEMI\n"); countColumns +=yyleng;}

"{"    				{printf("LBRACE\n"); countColumns +=yyleng;}
"}"    				{printf("RBRACE\n"); countColumns +=yyleng;}
"["    				{printf("LSQ\n"); countColumns +=yyleng;}
"]"    				{printf("RSQ\n"); countColumns +=yyleng;}
"("    				{printf("LPAR\n"); countColumns +=yyleng;}
")"    				{printf("RPAR\n"); countColumns +=yyleng;}

"-"    				{printf("MINUS\n"); countColumns +=yyleng;}
"+"    				{printf("PLUS\n"); countColumns +=yyleng;}
"%"    				{printf("MOD\n"); countColumns +=yyleng;}
"!"    				{printf("NOT\n"); countColumns +=yyleng;}
"||"    			{printf("OR\n"); countColumns +=yyleng;}




{INTLIT}			{printf("INTLIT(%s)\n", yytext); countColumns +=yyleng;}
{ID}				{printf("ID(%s)\n",yytext); countColumns +=yyleng;}




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
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}
