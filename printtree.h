#include <stdio.h>
#include "nodes.h"


class PrintWalker : public Visitor
{
private:
	uint _level;

	void print_indent();
public:
	PrintWalker() : _level(0) {}
	// void walk(const Node *node);
	// void walk(const ExprNode *node);
	// void walk(const IntegerNode *node);
	void visit(const Stmt *stmt);
	void visit(const Ident *ident);
	void visit(const VarDecl *decl);
	void visit(const Block *block);
};
