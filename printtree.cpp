#include "printtree.h"

void
PrintWalker::print_indent()
{
	int i;

	for (i=0; i<this->_level; i++)
		std::cout << '\t';
}

void
PrintWalker::visit(const Stmt *stmt)
{
	this->print_indent();
	std::cout << "<stmt>\n";
}

void
PrintWalker::visit(const Block *block)
{
	/* Block start */
	this->print_indent();
	std::cout << "{\n";
	this->_level++;

	/* Print statements */
	for(auto const& value: block->statements)
	{
		value->accept(this);
	}

	/* Block end */
	this->_level--;
	this->print_indent();
	std::cout << "}\n";
}

void
PrintWalker::visit(const VarDecl *decl)
{
	this->print_indent();
	decl->type->accept(this);
	std::cout << ' ';
	decl->var->accept(this);
	std::cout << ";\n";
}

void
PrintWalker::visit(const Ident *ident)
{
	std::cout << ident->name;
}
