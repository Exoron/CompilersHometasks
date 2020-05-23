#pragma once

#include "Expression.h"

class MulExpression: public Expression {
 public:
  MulExpression(Expression* left, Expression* right);
  ~MulExpression() override;
  int Eval() override;

 private:
  Expression* left_;
  Expression* right_;
};
