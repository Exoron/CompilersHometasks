#pragma once

#include <AbstractSyntaxTree/Expressions/BinaryExpression.h>

class DivExpression: public BinaryExpression {
 public:
  DivExpression(Expression* left, Expression* right);
  ~DivExpression() override = default;

  void Accept(Visitor* visitor) override;
};