#pragma once

#include <AbstractSyntaxTree/Expressions/BinaryExpression.h>

class Visitor;

class AddExpression: public BinaryExpression {
 public:
  AddExpression(Expression* left, Expression* right);
  ~AddExpression() override = default;

  void Accept(Visitor* visitor) override;
};