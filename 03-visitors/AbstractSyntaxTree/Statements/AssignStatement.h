#pragma once

#include <string>

#include <AbstractSyntaxTree/Statements/Statement.h>

class Expression;

class AssignStatement: public Statement {
 public:
  AssignStatement(const std::string& name, Expression* expr);
  ~AssignStatement() override;

  void Accept(Visitor* visitor) override;

  std::string Name() const;
  Expression* Value();

 private:
  const std::string name_;
  Expression* expr_;
};