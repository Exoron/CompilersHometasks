#include "PrintStatement.h"
#include <Visitors/Visitor.h>
#include <AbstractSyntaxTree/Expressions/Expression.h>

#include <iostream>

PrintStatement::PrintStatement(Expression* expr): expr_{expr} {}

PrintStatement::~PrintStatement() {
  delete expr_;
}

void PrintStatement::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

Expression* PrintStatement::Value() {
  return expr_;
}
