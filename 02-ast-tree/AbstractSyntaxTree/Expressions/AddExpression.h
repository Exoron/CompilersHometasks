#pragma once

#include "Expression.h"

class AddExpression: public Expression {
 public:
  AddExpression(Expression* left, Expression* right);
  ~AddExpression() override;

  int Eval() override;

 private:
  Expression* left_;
  Expression* right_;
};