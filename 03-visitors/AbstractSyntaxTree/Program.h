#pragma once

#include "Statements/StatementList.h"

class Program: public ASTNode {
 public:
  Program(StatementList* statements);
  ~Program() override;

  void Accept(Visitor* visitor) override;

  StatementList* List();

 private:
  StatementList* statements_;
};
