#include "Program.h"

Program::Program(StatementList* statements): statements_{statements} {}

void Program::Run() {
  statements_->Execute();
}

void Program::Print() {
  // Empty at the moment
}

Program::~Program() {
  delete statements_;
}
