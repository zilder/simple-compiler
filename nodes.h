#include <iostream>
#include <vector>


class Node
{
public:
	virtual ~Node();
};

class Stmt : public Node
{
};

class Expr : public Node
{
};

typedef std::vector<Stmt*> StatementList;

class IntegerNode : public Node
{
public:
	long value;
	IntegerNode(long value) : value(value) {}
};

class Ident : public Node
{
public:
	std::string name;
	Ident(const std::string name) : name(name) {}
};

class BinaryExpr : public Expr
{
public:
	int   op;
	Expr *left;
	Expr *right;
};

class VarDecl : public Stmt
{
public:
	Ident *type;
	Ident *var;
	VarDecl(Ident *type, Ident *var) : type(type), var(var) {}
};

class Block : public Node {
public:
    StatementList statements;
    Block() {}
};
