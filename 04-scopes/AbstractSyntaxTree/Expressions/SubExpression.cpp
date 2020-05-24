#include "SubExpression.h"
#include <Visitors/Visitor.h>

SubExpression::SubExpression(Expression* left, Expression* right)
    : BinaryExpression(left, right) {}

void SubExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
