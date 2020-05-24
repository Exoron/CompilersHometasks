#include "MulExpression.h"
#include <Visitors/Visitor.h>

MulExpression::MulExpression(Expression* left, Expression* right):
  BinaryExpression(left, right) {}

void MulExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
