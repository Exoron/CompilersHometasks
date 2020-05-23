#pragma once

#include "Expression.h"

class NumberExpression: public Expression {
 public:
  explicit NumberExpression(int n);
  ~NumberExpression() override = default;

  int Eval() override;

 private:
  int value_;
};
