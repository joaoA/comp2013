%{
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"
#include "shows.h"
#include "symbol_table.h"
#include "semantic.h"

extern int countLines;
extern int countColumns;
extern int yyleng;
extern char* yytext;

void yyerror (char *s);
int yylex(void);

is_node *myProgram;
prog_env *myProgramSemantic;

void show_program_semantic(table_element *table);

%}
%token RESERVED IF ELSE WHILE ATOI ITOA CHAR PRINTF RETURN EQ ASSIGN GE GT LE LT NE AMP AND AST
%token DIV COMMA SEMI LBRACE RBRACE LSQ RSQ LPAR RPAR MINUS PLUS MOD NOT OR INT UMINUS UPLUS

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
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left AST DIV MOD
%right NOT AMP
%nonassoc UMINUS UPLUS
%left LPAR RPAR LBRACE RBRACE LSQ RSQ
%nonassoc IF ELSE

%%
start: 		start functionDefinition    {$$=insert_link($1, $2);}
		|	start functionDeclaration 	{$$=insert_link($1, $2);}
		| 	start declaration           {$$=insert_link($1, $2);}
		|   functionDefinition          {$$=$1; myProgram=$$;} 
		|   functionDeclaration  		{$$=$1; myProgram=$$;}
		|   declaration 				{$$=$1; myProgram=$$;}
		;


functionDefinition: typeSpecifier functionDeclarator LBRACE new_eleven new_four RBRACE 	{
														$5=reverse($5);
														$4=reverse($4);
														is_node *body = insert_func_body(d_func_body, $4, $5); 
														$$=insert_function_definition(d_func_definition, $1, $2, body);
													}
		;

new_eleven: new_eleven declaration  						{$$=insert_link($2, $1);}
		| 													{$$=insert_token(d_null);}
		;

functionDeclaration: typeSpecifier functionDeclarator SEMI	{$$=insert_function_declaration(d_func_declaration, $1, $2);}
		;

functionDeclarator: new_six ID LPAR new_ten RPAR			{$$=insert_function_declarator(d_func_declarator, $1, insert_string(d_id, $2), $4);}
		;

new_ten: parameterList 										{$$=$1;}
		|													{$$=insert_token(d_null);}
		;

parameterList: parameterDeclaration new_nine				{/*$$=insert_param_list(d_param_list, $1, $2);*/$$=insert_link($1, $2); $$->next = reverse($$->next);}
		;

new_nine: new_nine COMMA parameterDeclaration 				{$$=insert_link($3, $1);}
		|													{$$=insert_token(d_null);}
		;

parameterDeclaration: typeSpecifier new_six ID 				{$$=insert_param_declaration(d_param_declaration, $1, $2, insert_string(d_id, $3));}
		;

declaration: typeSpecifier declarator new_eight SEMI		{$3=reverse($3); $$=insert_declaration(d_declaration, $1,$2, $3);}
		;

new_eight: new_eight COMMA declarator 						{$$=insert_link($3, $1);}
		|													{$$=insert_token(d_null);}
		;

typeSpecifier: INT 					{$$=insert_token(d_int);}
		|	CHAR 					{$$=insert_token(d_char);}
		;

declarator: new_six ID new_seven	{
										if($3->d_node==d_null){
											$$=insert_declarator(d_declarator, $1, insert_string(d_id, $2), $3);
										} else {
											$$=insert_declarator(d_array_declarator, $1, insert_string(d_id, $2), $3);
										}

									}
		;

new_six: new_six AST				{$$=insert_link(insert_token(d_pointer), $1);}
		|							{$$=insert_token(d_null);}
		;

new_seven: LSQ expression RSQ		{$$=$2;}
		| 							{$$=insert_token(d_null);}
		;

statement: SEMI													{$$=insert_token(d_null);}					
		|	expression SEMI										{$$=$1;}
		|	LBRACE new_four RBRACE								{
																	int count = compoundStatCounter($2); 
																	$2=reverse($2); 																	
																	if(count==0){
																		$$=insert_token(d_null);
																	} else if(count==1){
																		$$=insert_compound(d_stat, $2);	
																	} else {
																		$$=insert_compound(d_compound_stat, $2);	
																	}
																}

		|	IF LPAR expression RPAR statement ELSE statement	{
																	is_node * aux1;
																	is_node * aux2;
																	aux1 = $5;
																	aux2 = $7;

																	int conta = contaStatements($5);
     																int conta2 = contaStatements($7);

																	if(conta==0)
																		aux1 = insert_null_node();
																	
																	if(conta2==0)
																		aux2 = insert_null_node();

																	
																	$$=insert_if_else(d_if_else, $3, aux1, aux2);

																}	

																
		|	IF LPAR expression RPAR statement 					{


																	if($5->d_node == d_null){
																		$5 = insert_token(d_print_null);
 	 																	$$=insert_if(d_if,$3,insert_link(insert_token(d_print_null),$5));
																 	}else
																 		$$ = insert_if(d_if,$3,insert_link($5, insert_token(d_print_null)));

																}
		|	WHILE LPAR expression RPAR statement				{
																int conta = contaStatements($5);
																
																if(conta==0)
																	$$=insert_while(d_while, $3, insert_null_node());
																else
																	$$=insert_while(d_while, $3, $5);
																}

		|	RETURN expression SEMI								{$$=insert_return(d_return, $2);}
		;

new_four: new_four statement									{$$=insert_link($2, $1);}
		|														{$$=insert_token(d_null); }
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
		|	expression MINUS expression 					{$$=insert_infix_expression(d_sub, $1, $3);}
		|	expression PLUS expression   					{$$=insert_infix_expression(d_add, $1, $3);}
		|	NOT expression 									{$$=insert_unary_expression(d_not, $2);}
		|	MINUS expression %prec UMINUS					{$$=insert_unary_expression(d_minus, $2);}
		|	PLUS expression %prec UPLUS						{$$=insert_unary_expression(d_plus, $2);}
		|	AST expression 									{$$=insert_unary_expression(d_deref, $2);}
		|	AMP expression 									{$$=insert_unary_expression(d_addr, $2);}
		|	expression LSQ expression RSQ					{is_node *add = insert_add(d_add, $1, $3); $$=insert_unary_expression(d_deref, add);}
		|	ID LPAR new_one RPAR							{is_node * tmp = reverse($3->next); $3->next = tmp; tmp=insert_link(insert_string(d_id, $1), $3); $$=insert_call(d_call, tmp);}
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
		| 													{$$=insert_token(d_null);}
		;

new_two: new_two COMMA expression							{$$=insert_link($3, $1);}
		|													{$$=insert_token(d_null);}
		;

%%
int main(int argc, char *argv[])
{
	int i, show_tree = 0, show_semantic=0;

	if(yyparse()==0){

		myProgramSemantic = semantic_analysis(myProgram);

		for(i=0; i<argc; i++){
			if(strcmp(argv[i], "-t") == 0){
				show_tree = 1;
			} else if(strcmp(argv[i], "-s") == 0) {
				show_semantic = 1;
			}
			
		}

		if(show_tree == 1){
			printf("Program\n");
			show_program(myProgram, 1);
		} 
		if( show_semantic == 1){
			show_program_semantic(myProgramSemantic->global);
		}

	}
	return 0;
}

void yyerror (char *s) {

	countColumns -= yyleng;

	if(strcmp(yytext, "") == 0){
		countColumns++;
	}
	printf("Line %d, col %d: %s: %s\n", countLines, countColumns, s, yytext);
	
}

void show_program_semantic(table_element *table){

	table_element *aux;
	int i;

	printf("===== Global Symbol Table =====\n");

	for(aux=table; aux; aux = aux->next){

		printf("%s\t", aux->name);

		switch(aux->type_data.type){
			case(CHARe): printf("char"); break;
			case(INTe): printf("int"); break;
			case(FUNC): printf("function"); break;
			default: break;
		}

		for(i=0; i<aux->type_data.pointers; i++){
			printf("*");
		}

		if(aux->type_data.size!=-1){
			printf("[%d]", aux->type_data.size);
		}
		printf("\n");
	}

}