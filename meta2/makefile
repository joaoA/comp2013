all: 
	lex qcparser.l
	yacc -d qcparser.y --report all
	cc -o qcparser y.tab.c lex.yy.c functions.c shows.c -ly -ll -g
	zip qcparser.zip qcparser.l qcparser.y shows.c shows.h structures.h functions.c functions.h
clean:
	rm -rf qcparser y.tab.c lex.yy.c
