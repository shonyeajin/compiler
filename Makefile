CC= cc
LIBS= -ll
LEX= flex
YACC= bison
CFLAGS= -DYYDEBUG=1

all: translator
translator: y.tab.c lex.yy.c
	$(CC) -o translator y.tab.c lex.yy.c $(LIBS)
lex.yy.c: kim.l y.tab.h
	$(LEX) kim.l
y.tab.c: kim.y
	$(YACC) -d kim.y
y.tab.h: kim.y
	$(YACC) -d kim.y

