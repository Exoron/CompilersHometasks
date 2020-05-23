#pragma once

#include "Statements/Statement.h"
#include "Statements/StatementList.h"

class Program: public ASTNode {
 public:
  Program(StatementList* statements);
  ~Program() override;
  void Run();
  void Print();

 private:
  StatementList* statements_;
};
