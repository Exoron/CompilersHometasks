#include "DivExpression.h"
#include <Visitors/Visitor.h>

DivExpression::DivExpression(Expression* left, Expression* right):
  BinaryExpression(left, right) {}

void DivExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
