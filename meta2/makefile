all: 
	lex qcparser.l
	yacc -d qcparser.y --report all
	cc -o qcparser y.tab.c lex.yy.c functions.c -ly -ll 
	zip qcparser.zip qcparser.l qcparser.y
clean:
	rm -rf qcparser y.tab.c lex.yy.c
