#include "VariableExpression.h"
#include <Visitors/Visitor.h>

VariableExpression::VariableExpression(const std::string& name): name_{name} {}

void VariableExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

std::string VariableExpression::Name() const {
  return name_;
}