#include "DeclarationStatement.h"
#include "../../driver.hh"


DeclarationStatement::DeclarationStatement(Driver& driver,
                                           const std::string& ident,
                                           Expression* expr)
    : driver_{driver}, ident_{ident}, expr_{expr} {}

void DeclarationStatement::Execute() {
  driver_.variables[ident_] = expr_->Eval();
}

DeclarationStatement::~DeclarationStatement() {
  delete expr_;
}
