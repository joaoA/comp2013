#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"

int main()
{
int _ra;
int _rvi;
double _rvd;
char _rvc;
int _rvb;
frame* fp=NULL;
frame* sp=NULL;
char g0;
int g1;
double g2;

/*BLOCO DO PROCEDIMENTO fun1 */
/*Prologo*/
goto fun1skip;
fun1:
fp=sp;
sp=(frame*)malloc(sizeof(frame));
sp->parent=fp;
sp->return_address=_ra;
/*Corpo do procedimento*/
/*Declaracao dos argumentos b */
sp->outgoing[0]=(int*)malloc(sizeof(int));
*((int *)sp->outgoing[0])= 1;
/*Declaracao dos argumentos cenas */
sp->outgoing[1]=(double*)malloc(sizeof(double));
*((double*)sp->outgoing[1])= 400.0;
/*Declaracao da variavel a */
sp->locals[0]=(int*)malloc(sizeof(int));
*((int*)sp->locals[0])=124;
printf("%d\n", *((int*)(sp->locals[0])));
_rvi=*((int*)sp->locals[0]);
_ra=sp->return_address;
sp=sp->parent;
fp=sp->parent;
goto redirector;
printf("%d\n", *((int*)(sp->outgoing[0])));
printf("%f\n", *((double*)(sp->outgoing[1])));
/*Epilogo*/
_ra=sp->return_address;
sp=sp->parent;
fp=sp->parent;
goto redirector;
fun1skip:

/*BLOCO MAIN */
sp=(frame*)malloc(sizeof(frame));

/*vardecs*/
/*Declaracao da variavel x */
sp->locals[0]=(double*)malloc(sizeof(double));
/*Declaracao da variavel c */
sp->locals[1]=(int*)malloc(sizeof(int));
/*Declaracao da variavel f */
sp->locals[2]=(double*)malloc(sizeof(double));
/*Declaracao da variavel a */
sp->locals[3]=(int*)malloc(sizeof(int));
/*Declaracao da variavel as */
sp->locals[4]=(boolean*)malloc(sizeof(boolean));

/*statements*/
*((int*)sp->locals[1])=4;
g0='b';
*((double*)sp->locals[2])=400.0;
_ra=0;
goto fun1;
return0:
*((int*)sp->locals[1])=3.0*1.0+5.0+1.0/1.0;
*((int*)sp->locals[3])=2+1;
*((double*)sp->locals[0])=*((int*)sp->locals[1]);
g2=*((int*)sp->locals[1]);
*((int*)sp->locals[1])=g2;
g2=*((int*)sp->locals[3])+*((int*)sp->locals[3])**((int*)sp->locals[1]);
*((int*)sp->locals[3])=1;
scanf("%d",(int*)sp->locals[3]);
printf("%d\n", *((int*)(sp->locals[3])));
scanf("%lf",&g2);
printf("%f\n", g2);
scanf(" %c",&g0);
printf("%c\n", g0);
*((boolean*)sp->locals[4])=true;
if(*((double*)sp->locals[4])){
printf("111111111\n");

}*((int*)sp->locals[3])=2;
beforefor1:
if(*((int*)sp->locals[3])<10){

goto for1;
} 

goto forskip1;
for1:
*((int*)sp->locals[3])=1;
beforefor0:
if(*((int*)sp->locals[3])<10){

goto for0;
} 

goto forskip0;
for0:
printf("%d\n", *((int*)(sp->locals[3])));
*((int*)sp->locals[3])=*((int*)sp->locals[3])+2;

goto beforefor0;
forskip0:
printf("%d\n", *((int*)(sp->locals[3])));
printf("%d\n", *((int*)(sp->locals[3])));
*((int*)sp->locals[3])=*((int*)sp->locals[3])+1;

goto beforefor1;
forskip1:
/*Redirector*/
goto exit;
redirector:
if(_ra==0) goto return0;
exit:
;

}

