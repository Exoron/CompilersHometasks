#pragma once

#include <AbstractSyntaxTree/Statements/Statement.h>

#include <vector>

class StatementList: public Statement {
 public:
  StatementList() = default;
  ~StatementList() override;

  void AddStatement(Statement* statement);

  void Accept(Visitor* visitor) override;
  std::vector<Statement*>& Statements();

 private:
  std::vector<Statement*> statements_;
};
