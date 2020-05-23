#pragma once

#include <string>

#include "../Expressions/Expression.h"
#include "Statement.h"

class Driver;

class DeclarationStatement : public Statement {
 public:
  DeclarationStatement(Driver& driver, const std::string& ident,
                       Expression* expr);
  ~DeclarationStatement() override;

  void Execute() override;

 private:
  Driver& driver_;
  const std::string ident_;
  Expression* expr_;
};