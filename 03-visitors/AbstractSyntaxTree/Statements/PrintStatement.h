#pragma  once

#include <AbstractSyntaxTree/Statements/Statement.h>

class Expression;

class PrintStatement: public Statement {
 public:
  PrintStatement(Expression* expr);
  ~PrintStatement() override;

  void Accept(Visitor* visitor) override;

  Expression* Value();

 private:
  Expression* expr_;
};