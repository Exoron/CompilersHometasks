#include "AddExpression.h"
#include <Visitors/Visitor.h>

AddExpression::AddExpression(Expression* left, Expression* right)
    : BinaryExpression(left, right) {}

void AddExpression::Accept(Visitor* visitor) { visitor->Visit(this); }