#pragma once

#include <string>

#include <AbstractSyntaxTree/Statements/Statement.h>

class Expression;

class DeclarationStatement : public Statement {
 public:
  DeclarationStatement(const std::string& ident, Expression* expr);
  ~DeclarationStatement() override;

  void Accept(Visitor* visitor) override;

  std::string Name() const;
  Expression* Value();

 private:
  const std::string name_;
  Expression* expr_;
};