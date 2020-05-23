#pragma  once

#include "Statement.h"
#include "../Expressions/Expression.h"

class PrintStatement: public Statement {
 public:
  PrintStatement(Expression* expr);
  ~PrintStatement() override;

  void Execute() override;

 private:
  Expression* expr_;
};