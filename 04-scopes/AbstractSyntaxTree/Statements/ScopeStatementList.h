#pragma once

#include <AbstractSyntaxTree/Statements/Statement.h>

class StatementList;
class Visitor;

class ScopeStatementList: public Statement {
 public:
  ScopeStatementList(StatementList* statements);
  ~ScopeStatementList() override;

  void Accept(Visitor* visitor) override;
  StatementList* Statements();

 private:
  StatementList* statements_;
};
