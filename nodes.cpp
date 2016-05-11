#include "nodes.h"


void
VarDecl::accept(Visitor *v)
{
	v->visit(this);
}

void
Block::accept(Visitor *v)
{
	v->visit(this);
}

void
Ident::accept(Visitor *v)
{
	v->visit(this);
}
