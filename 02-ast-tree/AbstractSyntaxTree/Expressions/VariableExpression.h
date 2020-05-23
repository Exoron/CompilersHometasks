#pragma once

#include "Expression.h"

class VariableExpression: public Expression {
 public:
  explicit VariableExpression(int& var);
  ~VariableExpression() override = default;

  int Eval() override;

 private:
  int& variable_; // Invalidation ???
};

