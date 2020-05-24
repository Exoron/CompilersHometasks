#include "DeclarationStatement.h"
#include <Visitors/Visitor.h>
#include <AbstractSyntaxTree/Expressions/Expression.h>

DeclarationStatement::DeclarationStatement(const std::string& name,
                                           Expression* expr)
    : name_{name}, expr_{expr} {}

DeclarationStatement::~DeclarationStatement() {
  delete expr_;
}

void DeclarationStatement::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

std::string DeclarationStatement::Name() const {
  return name_;
}

Expression* DeclarationStatement::Value() {
  return expr_;
}