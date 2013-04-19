#ifndef _STRUCTURES_
#define _STRUCTURES_



/*is_new_twelve*/
typedef struct _s1{
}is_new_twelve;

/*is_declaration*/
typedef struct _s1{
}is_declaration;



/*is_functionDeclaration;*/
typedef struct _s1{
}is_functionDeclaration;



/*is_functionDefinition*/
typedef struct _s1{
}is_functionDefinition;



/*******************************************************/
/*****					start 					   *****/
/*******************************************************/

typedef enum {functionDefinition, functionDeclaration,declaration} disc_start;

/*is_start*/
typedef struct _s1{
	disc_start disc_s;		/* functionDefinition || functionDeclaration || declaration */
	is_new_twelve *isNewt;
	union{
		is_functionDefinition* isFuncDef;
		is_functionDeclaration* isFuncec;
		is_declaration* isDec;
	}data_start;
	struct _s1 *next;   /* start nao precisa disto!? n tem recursividade.... */
}is_start;



#endif