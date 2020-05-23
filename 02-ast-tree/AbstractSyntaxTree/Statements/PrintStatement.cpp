#include "PrintStatement.h"

#include <iostream>

PrintStatement::PrintStatement(Expression* expr): expr_{expr} {}

void PrintStatement::Execute() {
  std::cout << expr_->Eval() << std::endl;
}

PrintStatement::~PrintStatement() {
  delete expr_;
}
