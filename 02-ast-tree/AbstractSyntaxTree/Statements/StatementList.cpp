#include "StatementList.h"

void StatementList::Execute() {
  for(auto st: statements_) {
    st->Execute();
  }
}

void StatementList::AddStatement(Statement* statement) {
  statements_.push_back(statement);
}

StatementList::~StatementList() {
  for(auto statement: statements_) {
    delete statement;
  }
}
