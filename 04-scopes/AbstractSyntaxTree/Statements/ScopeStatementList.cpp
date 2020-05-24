#include "ScopeStatementList.h"
#include <AbstractSyntaxTree/Statements/StatementList.h>
#include <Visitors/Visitor.h>

#include <iostream>

ScopeStatementList::ScopeStatementList(StatementList* statements):
  statements_{statements} {}

ScopeStatementList::~ScopeStatementList() {
  delete statements_;
}

void ScopeStatementList::Accept(Visitor* visitor) {
  visitor->Visit(this);
}

StatementList* ScopeStatementList::Statements() {
  return statements_;
}
