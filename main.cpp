#include <iostream>
#include "nodes.h"
#include "printtree.h"


extern Block* programBlock;
extern int yyparse();

int main(int argc, char **argv)
{
	PrintWalker *walker;
    yyparse();
    // std::cout << programBlock << std::endl;
    walker = new PrintWalker();
    programBlock->accept(walker);
    return 0;
}
