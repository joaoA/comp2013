all: 
	lex qcparser.l
	yacc -d qcparser.y --report all
	cc -o qcparser lex.yy.c y.tab.c functions.c show.c -ly -ll
	zip qcparser.zip qcparser.l qcparser.y
clean:
	rm -rf qcparser y.tab.c y.tab.h lex.yy.c y.output 
