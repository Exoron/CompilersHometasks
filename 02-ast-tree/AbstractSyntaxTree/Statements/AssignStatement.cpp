#include "AssignStatement.h"

AssignStatement::AssignStatement(int& var, Expression* expr)
    : var_{var}, expr_{expr} {}

void AssignStatement::Execute() { var_ = expr_->Eval(); }

AssignStatement::~AssignStatement() {
  delete expr_;
}
