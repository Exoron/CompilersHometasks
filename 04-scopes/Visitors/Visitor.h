#pragma once

#include "declarations.h"

class Visitor {
 public:
  virtual ~Visitor() = default;

  virtual void Visit(NumberExpression*) = 0;
  virtual void Visit(VariableExpression*) = 0;
  virtual void Visit(AddExpression*) = 0;
  virtual void Visit(SubExpression*) = 0;
  virtual void Visit(MulExpression*) = 0;
  virtual void Visit(DivExpression*) = 0;
  virtual void Visit(StatementList*) = 0;
  virtual void Visit(AssignStatement*) = 0;
  virtual void Visit(DeclarationStatement*) = 0;
  virtual void Visit(PrintStatement*) = 0;
  virtual void Visit(Program*) = 0;
  virtual void Visit(ScopeStatementList*) = 0;
};