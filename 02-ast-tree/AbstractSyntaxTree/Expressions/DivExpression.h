#pragma once

#include "Expression.h"

class DivExpression: public Expression {
 public:
  DivExpression(Expression* left, Expression* right);
  ~DivExpression() override;

  int Eval() override;

 private:
  Expression* left_;
  Expression* right_;
};