#include "AssignStatement.h"
#include <Visitors/Visitor.h>
#include <AbstractSyntaxTree/Expressions/Expression.h>

AssignStatement::AssignStatement(const std::string& name, Expression* expr)
    : name_{name}, expr_{expr} {}

AssignStatement::~AssignStatement() {
  delete expr_;
}

void AssignStatement::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

std::string AssignStatement::Name() const {
  return name_;
}

Expression* AssignStatement::Value() {
  return expr_;
}