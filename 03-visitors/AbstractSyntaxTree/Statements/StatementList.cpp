#include "StatementList.h"
#include <Visitors/Visitor.h>

void StatementList::AddStatement(Statement* statement) {
  statements_.push_back(statement);
}

StatementList::~StatementList() {
  for(auto statement: statements_) {
    delete statement;
  }
}

void StatementList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

std::vector<Statement*>& StatementList::Statements() {
  return statements_;
}
