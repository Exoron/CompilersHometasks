#pragma once

#include "Statement.h"
#include "../Expressions/Expression.h"
#include "../Expressions/VariableExpression.h"

class AssignStatement: public Statement {
 public:
  AssignStatement(int& var, Expression* expr);
  ~AssignStatement() override;
  void Execute() override;

 private:
  int& var_;
  Expression* expr_;
};