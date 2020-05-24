#pragma once

#include <AbstractSyntaxTree/Expressions/BinaryExpression.h>

class MulExpression: public BinaryExpression {
 public:
  MulExpression(Expression* left, Expression* right);
  ~MulExpression() override = default;

  void Accept(Visitor* visitor) override;
};
