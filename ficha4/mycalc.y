%{

#include<stdio.h>
int sair=1;
%}
%token NUMBER
%token LeftP
%token RightP
%token END

%left '+''-'
%left '*''/'

%%
calc: 		expression 			{printf("%d\n", $1);}

expression:		expression '+' expression   {$$=$1+$3;}
			| 	expression '-' expression  	{$$=$1-$3;}
			| 	expression '/' expression  	{if($3==0){
												printf("Divide by zero!\n");
												return 0;
											}
											else
												$$=$1/$3;}
			| 	expression '*' expression  	{$$=$1*$3;}
			| 	NUMBER						{$$=$1;}
			|	LeftP expression RightP 	{$$=$2;}
			|   '-' expression				{$$=-$2;}
			| 	END 						{sair =0; return 0;}

	;

%%
int main()
{
	while(sair==1){
		yyparse();
	}
}
