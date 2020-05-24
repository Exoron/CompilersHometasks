#pragma once

#include <AbstractSyntaxTree/Expressions/Expression.h>
//class Expression;

class BinaryExpression: public Expression {
 public:
  BinaryExpression(Expression* left, Expression* right);
  ~BinaryExpression() override = default;
  Expression* Left();
  Expression* Right();

 private:
  Expression* left_;
  Expression* right_;
};