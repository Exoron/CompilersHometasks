#include "NumberExpression.h"
#include <Visitors/Visitor.h>

NumberExpression::NumberExpression(int n): value_{n} {}

void NumberExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

int NumberExpression::Value() {
  return value_;
}