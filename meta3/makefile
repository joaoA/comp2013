all: 
	lex qccompiler.l
	yacc -d qccompiler.y --report all
	gcc -o qccompiler *.c -ly -ll -g
	zip qccompiler.zip qccompiler.l qccompiler.y shows.c shows.h structures.h functions.c functions.h semantic.c semantic.h symbol_table.h
clean:
	rm -rf qccompiler y.tab.c lex.yy.c
