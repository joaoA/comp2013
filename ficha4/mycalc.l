%{
#include "y.tab.h"
extern int yylval;  /* Para partilhar yylval*/
%}
%%
[0-9]+  	{yylval=atoi(yytext);  /*Guarda valor em yylval e*/
        	return NUMBER;}	  	/*envia token reconhecido ao YACC*/


"end"		{return END;}

"("			{return LeftP;}
")"			{return RightP;}

\n 	     	{return 0;}		/*Fim = sinal de EOF para YACC */

[ \t]  		; 			/*Ignorar espaço e tab*/

. 	      	return yytext[0];	/*Caso seja qualquer outro */
				/*caracter (por exemplo um */
				/*operador), enviar para   */
				/*o YACC*/
%%
int yywrap()
{
return 1;
}

