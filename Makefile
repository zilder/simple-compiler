
all: lex bison

lex:
	flex tokens.l
	$(CXX) $(CFLAGS) -c lex.yy.c -o lex.o

bison:
	bison -d -v gram.y
	$(CXX) $(CFLAGS) -c gram.tab.c -o bison.o
