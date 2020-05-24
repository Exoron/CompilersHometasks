#pragma once

#include <AbstractSyntaxTree/Expressions/BinaryExpression.h>

class SubExpression: public BinaryExpression {
 public:
  SubExpression(Expression* left, Expression* right);
  ~SubExpression() override = default;

  void Accept(Visitor* visitor) override;
};
