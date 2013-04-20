all: 
	lex qcparser.l
	yacc -d qcparser.y --report all
	gcc -o qcparser lex.yy.c y.tab.c functions.c show.c -ly -ll
	zip qcparser.zip qcparser.l qcparser.y
clean:
	rm -rf qcparser y.tab.c lex.yy.c
