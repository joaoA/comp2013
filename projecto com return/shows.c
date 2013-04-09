#include "structures.h"
#include "shows.h"
#include <stdio.h>


void show_block_list(is_block_list* ipl)
{
	is_block_list* aux;

	for(aux=ipl; aux; aux=aux->next)
		show_block(aux->p);
}

void show_block(is_block* ip)
{
	switch(ip->disc_d)
	{
	case d_globals: show_globals(ip->data_block.u_globals);break;
	case d_procedure:show_procedure(ip->data_block.u_procedure);break;
	}		
}


void show_procedure(is_procedure* ipr)
{
	printf("(procedure %s \n", ipr->name);
	show_vardec_list(ipr->vlist);
	show_statement_list(ipr->slist);
	printf(")\n");
}


void show_globals(is_globals* ipg)
{
	printf("(global \n");
	show_vardec_list(ipg->vlist);
	printf(")\n");
}


void show_vardec_list(is_vardec_list* ivl)
{
	is_vardec_list* aux;

	printf("\t(vardecs ");
	for(aux=ivl; aux; aux=aux->next)
		show_vardec(aux->v);
	printf(")\n");
}


void show_vardec(is_vardec* iv)
{
	switch(iv->disc_d)
	{
	case integer:	printf("(int %s)", iv->name); break;
	case character:	printf("(char %s)", iv->name); break;
	case doub:		printf("(double %s)", iv->name); break;
	default: printf("error in declaration!");
	}
}

void show_statement_list(is_statement_list* isl)
{
	is_statement_list* aux;
	printf("\t(statements ");
	for(aux=isl; aux; aux=aux->next)
		show_statement(aux->s);
	printf(")");
}


void show_statement(is_statement* is)
{
	switch(is->disc_d)
	{
	case d_write_stat: show_write_stat(is->data_statement.u_write_stat); break;
	case d_assgn_stat: show_assgn_stat(is->data_statement.u_assgn_stat);break;
	case d_call_stat: show_call_stat(is->data_statement.u_call_stat);break;
	}

}	


void show_write_stat(is_write_stat* iws)
{
	printf("(write %s)", iws->var);
}

void show_call_stat(is_call_stat* ics)
{
	printf("(call %s)", ics->proc);
}


void show_assgn_stat(is_assgn_stat* ias)
{
	switch(ias->disc_d)
	{
//	case integer:	printf("(= %s %d)", ias->var, ias->data_assgn_stat.i); break;
	case character:	printf("(= %s %c)", ias->var, ias->data_assgn_stat.c); break;
//	case doub:		printf("(= %s %f)", ias->var, ias->data_assgn_stat.d); break;
	case bool:
		if(ias->data_assgn_stat.b == 0)
			printf("(= %s false)",ias->var);
		else
			printf("(= %s true)",ias->var);
		break;
	}
}

