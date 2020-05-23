#pragma once

#include "Statement.h"
#include <vector>

class StatementList: public Statement {
 public:
  StatementList() = default;
  ~StatementList() override;

  void Execute() override;

  void AddStatement(Statement* statement);

 private:
  std::vector<Statement*> statements_;
};
