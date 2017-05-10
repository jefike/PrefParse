CC = gcc -Wall

pref_parse: driver.c parse.c genpairs.c parse2.c lex.yy.c global.h
	$(CC) -o pp driver.c parse.c genpairs.c parse2.c lex.yy.c
debug:
	$(CC) -DDEBUG -o pp driver.c parse.c parse2.c genpairs.c lex.yy.c
lex.yy.c: scan.l
	flex scan.l
clean:
	rm pp lex.yy.c

test:
	./pp < test.txt
