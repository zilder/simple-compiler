#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <vector>

class Visitor;

class Node
{
public:
	virtual ~Node() {}
	virtual void accept(Visitor *v) = 0;
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
	virtual void accept(Visitor *v);
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
	void accept(Visitor *v);
};

class Block : public Node {
public:
    StatementList statements;
    Block() {}
    void accept(Visitor *v);
};


class Visitor
{
public:
	// void visit(const Stmt *stmt);
	virtual void visit(const Ident *ident) = 0;
	virtual void visit(const VarDecl *decl) = 0;
	virtual void visit(const Block *block) = 0;
};

#endif
