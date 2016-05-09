
all: bison lex
	$(CXX) $(CFLAGS) -o compiler main.cpp gram.tab.c lex.yy.c

lex:
	flex tokens.l
	$(CXX) $(CFLAGS) -c lex.yy.c -o lex.o

bison:
	bison -d -v gram.y
	$(CXX) $(CFLAGS) -c gram.tab.c -o bison.o

clean:
	rm -f compiler
	rm -f bison.o
	rm -f lex.o
	rm -f gram.tab.h
	rm -f gram.tab.c
	rm -f gram.output
	rm -f lex.yy.c
