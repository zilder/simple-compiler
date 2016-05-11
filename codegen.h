#include <stdio.h>
#include "llwm/IR/Value.h"
#include "nodes.hpp"

class CodegenWalker
{
	Value *walk(const Node *node);
	Value *walk(const ExprNode *node);
	Value *walk(const IntegerNode *node);
	Value *walk(const IdentNode *node);		
};
