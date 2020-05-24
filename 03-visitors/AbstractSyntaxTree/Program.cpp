#include "Program.h"
#include <Visitors/Visitor.h>

Program::Program(StatementList* statements): statements_{statements} {}

Program::~Program() {
  delete statements_;
}

StatementList* Program::List() {
  return statements_;
}

void Program::Accept(Visitor* visitor) {
  visitor->Visit(this);
}