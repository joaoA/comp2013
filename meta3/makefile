all: 
	lex qccompiler.l
	yacc -d qccompiler.y --report all
	cc -o qccompiler y.tab.c lex.yy.c functions.c shows.c -ly -ll -g
	zip qccompiler.zip qccompiler.l qccompiler.y shows.c shows.h structures.h functions.c functions.h
clean:
	rm -rf qccompiler y.tab.c lex.yy.c
