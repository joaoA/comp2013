#include "translate.h"
#include "structures.h"
#include "semantic.h"
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

int returncounter=0;

void translate_procedure(FILE* dest, is_procedure* ip, prog_env* pe)
{

	environment_list* localenv=plookup(pe->procs, ip->name);	


	fprintf(dest, "\n/*BLOCO DO PROCEDIMENTO %s */\n", ip->name); 
	fprintf(dest, "/*Prologo*/\n");
	fprintf(dest, "goto %sskip;\n", ip->name);		
	fprintf(dest, "%s:\n",ip->name);			
	fprintf(dest, "fp=sp;\n");				
	fprintf(dest, "sp=(frame*)malloc(sizeof(frame));\n");	
	fprintf(dest, "sp->parent=fp;\n");			
	fprintf(dest, "sp->return_address=_ra;\n");		
	

	fprintf(dest, "/*Corpo do procedimento*/\n");
	translate_args_vardecs(dest, ip->avlist, localenv, pe);	//translate dos argumentos da funcao
	translate_vardecs(dest, ip->vlist, localenv, pe);			
	translate_statements(dest, ip->slist, localenv,ip->name, pe);		


	fprintf(dest, "/*Epilogo*/\n");
	fprintf(dest, "_ra=sp->return_address;\n");		
	fprintf(dest, "sp=sp->parent;\n");			
	fprintf(dest, "fp=sp->parent;\n");			
	fprintf(dest, "goto redirector;\n");			
	fprintf(dest, "%sskip:\n", ip->name); 			
}

void translate(is_block_list* list, prog_env* pe)
{
FILE *dest;
dest=fopen("result.c", "w");		


translate_header(dest);
translate_global_list(dest, pe);
translate_block_list(dest, list, pe);
translate_footer(dest);

fclose(dest);
}


void translate_header(FILE* dest)
{
	fprintf(dest, "#include \"frame.h\"\n");
	fprintf(dest, "#include <stdlib.h>\n");
	fprintf(dest, "#include <stdio.h>\n");
	fprintf(dest, "#include \"structures.h\"\n\n");
	fprintf(dest, "int main()\n{\n");
	fprintf(dest, "int _ra;\n");
	fprintf(dest, "int _rvi;\n");
	fprintf(dest, "double _rvd;\n");
	fprintf(dest, "char _rvc;\n");
	fprintf(dest, "int _rvb;\n");
	fprintf(dest, "frame* fp=NULL;\n");
	fprintf(dest, "frame* sp=NULL;\n");

}

void translate_footer(FILE* dest)
{
	translate_redirector(dest);
	fprintf(dest, "\n}\n\n");
}


void translate_block_list(FILE* dest, is_block_list* ipl, prog_env* pe)
{
	is_block_list* aux;
	environment_list* etmp=pe->procs;


	for(aux=ipl; aux; aux=aux->next)
		{
		if(aux->p->disc_d==d_globals)   
			continue;
		translate_block(dest, aux->p, etmp, pe);
		etmp=etmp->next;		
		}
	
}	

void translate_block(FILE* dest, is_block* ip, environment_list* etmp, prog_env* pe)
{
	if(strcmp(ip->data_block.u_procedure->name, "main")==0)
		translate_main(dest, ip->data_block.u_procedure, etmp, pe);
	else
		translate_procedure(dest, ip->data_block.u_procedure, pe);
}



void translate_global_list(FILE* dest, prog_env* pe)
{
	table_element* gtable=pe->global;

	for(;gtable; gtable=gtable->next)
		translate_global_vardec(dest, gtable->type, gtable->offset);

}

void translate_global_vardec(FILE* dest, basic_type type, int offset)
{

	switch(type)
	{
	case integer:	fprintf(dest, "int g%d;\n", offset); break;
	case character:	fprintf(dest, "char g%d;\n", offset); break;
	case doub:	fprintf(dest, "double g%d;\n", offset); break;
	case bool:	
		switch(offset){
		case false:
			fprintf(dest, "boolean g%d;\n", offset); break;
			break;
		
		case true:
			fprintf(dest, "boolean g%d;\n", offset); break;
			break;
		}
			
	default:break;
	}
}

void translate_main(FILE* dest, is_procedure* main, environment_list* local, prog_env* pe)
{
	fprintf(dest, "\n/*BLOCO MAIN */\n");
	fprintf(dest, "sp=(frame*)malloc(sizeof(frame));\n");
	fprintf(dest, "\n/*vardecs*/\n");
	translate_vardecs(dest, main->vlist, local, pe);
	fprintf(dest, "\n/*statements*/\n");
	translate_statements(dest, main->slist, local,main->name, pe);	
}

void translate_args_vardecs(FILE* dest, is_args_vardec_list* ivl, environment_list* local, prog_env* pe)
{
	is_args_vardec_list* aux;

	for(aux=ivl; aux; aux=aux->next)
		translate_args_vardec(dest, aux->av, local, pe);
		
}

void print_args_vardec(FILE* dest, is_args_vardec* iav, environment_list* local, prog_env* pe,table_element* t)
{
	is_expression_list* aux;
	for(aux=iav->list;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			printf("%s",aux->expression->cod);
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){

				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}
				
				fprintf(dest, "sp->outgoing[%d])", tb->offset);
				
			}
			
		}
	}
	
	fprintf(dest, ";\n");
}




void translate_args_vardec(FILE* dest, is_args_vardec* iav, environment_list* local, prog_env* pe)
{
	table_element* t=lookup(local->locals, iav->name);

	fprintf(dest, "/*Declaracao dos argumentos %s */\n",iav->name);
	switch(iav->type)
	{
		case integer:	fprintf(dest, "sp->outgoing[%d]=(int*)malloc(sizeof(int));\n*((int *)sp->outgoing[%d])= ",t->offset, t->offset);
				if(iav->veri == 1)
					fprintf(dest,"%d;\n",iav->data_args.i);
				else
					print_args_vardec(dest, iav, local, pe,t);
		break;
		case character:	fprintf(dest, "sp->outgoing[%d]=(char*)malloc(sizeof(char));\n*((char*)sp->outgoing[%d])= '%c';\n",t->offset, t->offset,iav->data_args.c); break;
		case doub:	fprintf(dest, "sp->outgoing[%d]=(double*)malloc(sizeof(double));\n*((double*)sp->outgoing[%d])= ",t->offset, t->offset);
				if(iav->veri == 1)
					fprintf(dest,"%f;\n",iav->data_args.d);
				else
					print_args_vardec(dest, iav, local, pe,t);
		break;
		case bool:
			if(iav->data_args.b == 0)
				fprintf(dest, "sp->outgoing[%d]=(boolean*)malloc(sizeof(boolean));\n*((boolean*)sp->outgoing[%d])=false;\n", t->offset,t->offset);
			else
				fprintf(dest, "sp->outgoing[%d]=(boolean*)malloc(sizeof(boolean));\n*((boolean*)sp->outgoing[%d])=true;\n", t->offset,t->offset);
		break;		
		default: break;
	}
}

void translate_vardecs(FILE* dest, is_vardec_list* ivl, environment_list* local, prog_env* pe)
{
	is_vardec_list* aux;

	for(aux=ivl; aux; aux=aux->next)
		translate_vardec(dest, aux->v, local, pe);
		
}


void translate_vardec(FILE* dest, is_vardec* iv, environment_list* local, prog_env* pe)
{
	table_element* t=lookup(local->locals, iv->name);

	fprintf(dest, "/*Declaracao da variavel %s */\n",iv->name);
	switch(iv->disc_d)
	{
	case integer:	fprintf(dest, "sp->locals[%d]=(int*)malloc(sizeof(int));\n", t->offset); break;
	case character:	fprintf(dest, "sp->locals[%d]=(char*)malloc(sizeof(char));\n", t->offset); break;
	case doub:	fprintf(dest, "sp->locals[%d]=(double*)malloc(sizeof(double));\n", t->offset); break;
	case bool:	fprintf(dest, "sp->locals[%d]=(boolean*)malloc(sizeof(boolean));\n", t->offset); break;
	default: break;
	}
}

void translate_statements(FILE* dest, is_statement_list* isl,environment_list* local,char *nameProc , prog_env* pe)
{
	is_statement_list* aux;

	for(aux=isl; aux; aux=aux->next)
		translate_statement(dest, aux->s, local,nameProc, pe);
	
}

void translate_statement(FILE* dest, is_statement* is, environment_list* local,char *nameProc, prog_env* pe)
{
	switch(is->disc_d)
	{
	case d_write_stat:  translate_write_stat(dest, is->data_statement.u_write_stat, local, pe); 	break;
	case d_assgn_stat:  translate_assgn_stat(dest, is->data_statement.u_assgn_stat, local, pe);	break;
	case d_call_stat:   translate_call_stat(dest, is->data_statement.u_call_stat, pe);	break;
	case d_if_stat:     translate_if_stat(dest, is->data_statement.u_if_stat, local,nameProc, pe);		break;
	case d_if_else_stat:translate_if_else_stat(dest, is->data_statement.u_if_else_stat, local,nameProc, pe);	break;
	case d_while_stat:  translate_while_stat(dest, is->data_statement.u_while_stat, local,nameProc, pe);	break;
	case d_for_stat:    translate_for_stat(dest, is->data_statement.u_for_stat, local,nameProc ,pe);break;
	case d_return_stat: translate_return_stat(dest, is->data_statement.u_return_stat, local,nameProc, pe);	break;
	}
}
void translate_return_stat(FILE* dest, is_return_statement* irs, environment_list* local,char *nameProc, prog_env* pe)
{

	table_element *aux;
	printf("\nainda nao\n");
	printf("\n NAO\n");
	
	environment_list *p;

	p=plookup(pe->procs, nameProc);
	table_element *t= p->locals;
	show_table(t);
	while(t!=NULL){
		if(strcmp(t->name,irs->name)==0){
			if(t->isArg == 2){
				switch(t->type){
					case integer: 	fprintf(dest, "_rvi=*((int*)sp->outgoing[%d]);\n",t->offset);break;
					case doub: 	fprintf(dest, "_rvd=*((double*)sp->outgoing[%d]);\n",t->offset);break;
					case character:	fprintf(dest, "_rvc=*((char*)sp->outgoing[%d]);\n",t->offset);break;
					case bool:	fprintf(dest, "_rvb=*((boolean*)sp->outgoing[%d]);\n",t->offset);break;
				}
			}
			else{
				switch(t->type){
					case integer: 	fprintf(dest, "_rvi=*((int*)sp->locals[%d]);\n",t->offset);break;
					case doub: 	fprintf(dest, "_rvd=*((double*)sp->locals[%d]);\n",t->offset);break;
					case character:	fprintf(dest, "_rvc=*((char*)sp->locals[%d]);\n",t->offset);break;
					case bool:	fprintf(dest, "_rvb=*((boolean*)sp->locals[%d]);\n",t->offset);break;
				}
			}
			break;
			
		}
		t=t->next;
	}
	if(t==NULL){
		t=lookup(pe->global, irs->name);
		switch(t->type){
			case integer: 	fprintf(dest, "_rvi=g%d;\n",t->offset);break;
			case doub: 	fprintf(dest, "_rvd=g%d;\n",t->offset);break;
			case character:	fprintf(dest, "_rvc=g%d;\n",t->offset);break;
			case bool:	fprintf(dest, "_rvb=g%d;\n",t->offset);break;
				break;
		}
		
	}

	fprintf(dest, "_ra=sp->return_address;\n");		
	fprintf(dest, "sp=sp->parent;\n");			
	fprintf(dest, "fp=sp->parent;\n");	
	fprintf(dest, "goto redirector;\n");
}
void translate_for_stat(FILE* dest, is_for_stat* ifs, environment_list* local,char *nameProc , prog_env* pe){

	

	translate_statement(dest,ifs->inicial,local,nameProc,pe);

	fprintf(dest,"beforefor%d:\n",ifs->n_for);
	is_expression_list* aux;

	fprintf(dest,"if(");
	for(aux=ifs->boolean;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){
				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}

				fprintf(dest, "sp->locals[%d])", tb->offset);
			}
			else{
				tb=lookup(pe->global, aux->expression->cod);
				fprintf(dest, "g%d", tb->offset);
			}
		}
	}

	fprintf(dest, "){\n");


	fprintf(dest, "\ngoto for%d;\n} \n\ngoto forskip%d;\n",ifs->n_for,ifs->n_for);
	fprintf(dest, "for%d:\n",ifs->n_for);
	is_statement_list* aux1=ifs->list;
	for(; aux1; aux1=aux1->next)
		translate_statement(dest, aux1->s, local, nameProc,pe);
	translate_statement(dest, ifs->loop_stat, local, nameProc,pe);
	fprintf(dest, "\ngoto beforefor%d;\nforskip%d:\n",ifs->n_for,ifs->n_for);

	
}


void translate_write_stat(FILE* dest, is_write_stat* iws, environment_list* local, prog_env* pe)
{
	table_element* t;

	if(strcmp(iws->var, "")==0){
		switch(iws->type){
			case integer:	fprintf(dest, "printf(\"%d\\n\");\n", iws->values.i); break;
			case character:	fprintf(dest, "printf(\"%c\\n\");\n", iws->values.c); break;
			case doub:	fprintf(dest, "printf(\"%f\\n\");\n", iws->values.d); break;
			case bool:	
					fprintf(dest,"if (%d == false)\n printf(\"false\\n\");\nif(%d == true)\nprintf(\"true\\n\");\n",iws->values.b,iws->values.b);
					break;
			}
		return;
	}
	
	t=lookup(local->locals, iws->var);

	if(t==NULL){
		t=lookup(pe->global, iws->var);
		switch(t->type){	
			case integer:	fprintf(dest, "printf(\"%%d\\n\", g%d);\n", t->offset); break;
			case character:	fprintf(dest, "printf(\"%%c\\n\", g%d);\n", t->offset); break;
			case doub:	fprintf(dest, "printf(\"%%f\\n\", g%d);\n", t->offset); break;
			case bool:	
				fprintf(dest,"if (g%d == false)\n printf(\"false\\n\");\nif(g%d == true)\nprintf(\"true\\n\");\n",t->offset,t->offset);
					break;
		}
	}
	else{
		if(t->isArg == 2){
			switch(t->type){
				case integer:	fprintf(dest, "printf(\"%%d\\n\", *((int*)(sp->outgoing[%d])));\n", t->offset); break;
				case character:	fprintf(dest, "printf(\"%%c\\n\", *((char*)(sp->outgoing[%d])));\n", t->offset); break;
				case doub:	fprintf(dest, "printf(\"%%f\\n\", *((double*)(sp->outgoing[%d])));\n", t->offset); break;
				case bool:	
					fprintf(dest,"if (*((boolean*)(sp->outgoing[%d])) == false)\nprintf(\"false\\n\");\nif(*((boolean*)(sp->outgoing[%d])) == true)\nprintf(\"true\\n\");\n",t->offset,t->offset);
					break;
			}	

		}
		else{
		
			switch(t->type){	
				case integer:	fprintf(dest, "printf(\"%%d\\n\", *((int*)(sp->locals[%d])));\n", t->offset); break;
				case character:	fprintf(dest, "printf(\"%%c\\n\", *((char*)(sp->locals[%d])));\n", t->offset); break;
				case doub:	fprintf(dest, "printf(\"%%f\\n\", *((double*)(sp->locals[%d])));\n", t->offset); break;
				case bool:	
					fprintf(dest,"if (*((boolean*)(sp->locals[%d])) == false)\nprintf(\"false\\n\");\nif(*((boolean*)(sp->locals[%d])) == true)\nprintf(\"true\\n\");\n",t->offset,t->offset);
					break;
				}
		}
	}
}

void translate_while_stat(FILE* dest, is_while_stat* iws, environment_list* local,char *nameProc , prog_env* pe){
	
	fprintf(dest,"beforewhile%d:\n",iws->n_while);
	is_expression_list* aux;

	fprintf(dest,"if(");
	for(aux=iws->boolean;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){
				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}

				if(tb->isArg == 2)
					fprintf(dest, "sp->outgoing[%d])", tb->offset);
				else
					fprintf(dest, "sp->locals[%d])", tb->offset);
			}
			else{
				tb=lookup(pe->global, aux->expression->cod);
				fprintf(dest, "g%d", tb->offset);
			}
		}
	}

	fprintf(dest, "){\n");


	fprintf(dest, "\ngoto while%d;\n} \n\ngoto whileskip%d;\n",iws->n_while,iws->n_while);
	fprintf(dest, "while%d:\n",iws->n_while);
	is_statement_list* aux1=iws->statement_list;
	for(; aux1; aux1=aux1->next)
		translate_statement(dest, aux1->s, local, nameProc,pe);
	fprintf(dest, "\ngoto beforewhile%d;\nwhileskip%d:\n",iws->n_while,iws->n_while);




}

void translate_if_stat(FILE* dest, is_if_stat* ifs, environment_list* local,char *nameProc , prog_env* pe){
	
	is_statement_list* aux1=ifs->statement_list;

	is_expression_list* aux;
	fprintf(dest,"if(");
	for(aux=ifs->boolean;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){
				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}
				if(tb->isArg == 2)
					fprintf(dest, "sp->outgoing[%d])", tb->offset);
				else
					fprintf(dest, "sp->locals[%d])", tb->offset);
			}
			else{
				tb=lookup(pe->global, aux->expression->cod);
				fprintf(dest, "g%d", tb->offset);
			}
		}
	}

	fprintf(dest, "){\n");
	for(; aux1; aux1=aux1->next)
		translate_statement(dest, aux1->s, local,nameProc, pe);

	fprintf(dest, "\n}");



}


void translate_if_else_stat(FILE* dest, is_if_else_stat* ifs, environment_list* local,char *nameProc, prog_env* pe){
	
	
	is_statement_list* aux1=ifs->statement_list;

	is_expression_list* aux;
	fprintf(dest,"if(");
	for(aux=ifs->boolean;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){
				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}
				if(tb->isArg == 2)
					fprintf(dest, "sp->outgoing[%d])", tb->offset);
				else
					fprintf(dest, "sp->locals[%d])", tb->offset);
			}
			else{
				tb=lookup(pe->global, aux->expression->cod);
				fprintf(dest, "g%d", tb->offset);
			}
		}
	}

	fprintf(dest, "){\n");
	for(; aux1; aux1=aux1->next)
		translate_statement(dest, aux1->s, local, nameProc,pe);
	
	fprintf(dest, "\ngoto ifskip%d;\n}\n",ifs->n_if);

	for(aux1=ifs->statement_list2; aux1; aux1=aux1->next)
		translate_statement(dest, aux1->s, local, nameProc,pe);

	fprintf(dest, "\nifskip%d:\n",ifs->n_if);

}


void print_assgn(FILE* dest, is_assgn_stat* ias, environment_list* local, prog_env* pe,table_element* t)
{
	is_expression_list* aux;

	for(aux=ias->list;aux;aux=aux->next){
		if(aux->expression->type==not_var){
			fprintf(dest, "%s",aux->expression->cod);
		}
		else{
			table_element* tb;
			tb=lookup(local->locals, aux->expression->cod);
			if(tb!=NULL){
				if(tb->type==integer){
					fprintf(dest,"*((int*)");			
				}
				else{
					fprintf(dest,"*((double*)");			
				}
				if(tb->isArg == 2)
					fprintf(dest, "sp->outgoing[%d])", tb->offset);
				else
					fprintf(dest, "sp->locals[%d])", tb->offset);
			}
			else{
				tb=lookup(pe->global, aux->expression->cod);
				fprintf(dest, "g%d", tb->offset);
			}
		}
	}
	
	fprintf(dest, ";\n");
}

void translate_assgn_stat(FILE* dest, is_assgn_stat* ias, environment_list* local, prog_env* pe)
{
	table_element* t;
	t=lookup(local->locals, ias->var);
	if(t==NULL){
		t=lookup(pe->global, ias->var);
		switch(ias->disc_d){
			case integer:	fprintf(dest, "g%d=", t->offset); 
					print_assgn(dest,ias,local,pe,t);			break;
			case character:	fprintf(dest, "g%d='%c';\n", t->offset, ias->data_assgn_stat.c); break;
			case doub:	
					fprintf(dest, "g%d=", t->offset); 
					print_assgn(dest,ias,local,pe,t);		
					break;
			case bool:
				if(ias->data_assgn_stat.b == 0)
					fprintf(dest, "g%d=false;\n", t->offset);
				else
					fprintf(dest, "g%d=true;\n", t->offset); 
				break;
			case input_int: fprintf(dest, "scanf(\"%%d\",&g%d);\n", t->offset); break;
			case input_double: fprintf(dest, "scanf(\"%%lf\",&g%d);\n", t->offset); break;
			case input_char: fprintf(dest, "scanf(\" %%c\",&g%d);\n", t->offset); break;
			}	
	}
	else{	
		if(t->isArg == 2){
			switch(ias->disc_d){
				case integer:	fprintf(dest, "*((int*)sp->outgoing[%d])=", t->offset); 
						print_assgn(dest,ias,local,pe,t);
				break;
				case character:	fprintf(dest, "*((char*)sp->outgoing[%d])='%c';\n", t->offset, ias->data_assgn_stat.c); break;
				case doub:	fprintf(dest, "*((double*)sp->outgoing[%d])=", t->offset); 
						print_assgn(dest,ias,local,pe,t);
						break;
				case bool:
				if(ias->data_assgn_stat.b == 0)
					fprintf(dest, "*((boolean*)sp->outgoing[%d])=false;\n", t->offset);
				else
					fprintf(dest, "*((boolean*)sp->outgoing[%d])=true;\n", t->offset);
				break;
			}	

		}
		switch(ias->disc_d){
			case integer:	fprintf(dest, "*((int*)sp->locals[%d])=", t->offset); 
					print_assgn(dest,ias,local,pe,t);break;
			case character:	fprintf(dest, "*((char*)sp->locals[%d])='%c';\n", t->offset, ias->data_assgn_stat.c); break;
			case doub:	fprintf(dest, "*((double*)sp->locals[%d])=", t->offset); 
					print_assgn(dest,ias,local,pe,t);break;
			case input_int: fprintf(dest, "scanf(\"%%d\",(int*)sp->locals[%d]);\n", t->offset); break;
			case input_double: fprintf(dest, "scanf(\"%%lf\",(double*)sp->locals[%d]);\n", t->offset); break;
			case input_char: fprintf(dest, "scanf(\" %%c\",(char*)sp->locals[%d]);\n", t->offset); break;
			case bool:
				if(ias->data_assgn_stat.b == 0)
					fprintf(dest, "*((boolean*)sp->locals[%d])=false;\n", t->offset);
				else
					fprintf(dest, "*((boolean*)sp->locals[%d])=true;\n", t->offset);
				break;
		}	
	}	
		
}

void translate_call_stat(FILE* dest, is_call_stat* ias, prog_env* pe)
{

	fprintf(dest, "_ra=%d;\n",returncounter);		
	fprintf(dest, "goto %s;\n", ias->proc);			
	fprintf(dest, "return%d:\n", returncounter);		
	returncounter++;	
}




void translate_redirector(FILE* dest)
{
	int i;
	fprintf(dest, "/*Redirector*/\n");
	fprintf(dest, "goto exit;\n");
	fprintf(dest, "redirector:\n");

	for(i=0; i<returncounter; i++)				
		{
		fprintf(dest, "if(_ra==%d) goto return%d;\n", i, i);
		}
	fprintf(dest, "exit:\n;\n");
}



