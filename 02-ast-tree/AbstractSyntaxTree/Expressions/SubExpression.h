#pragma once

#include "Expression.h"

class SubExpression: public Expression {
 public:
  SubExpression(Expression* left, Expression* right);
  ~SubExpression() override;

  int Eval() override;

 private:
  Expression* left_;
  Expression* right_;
};
