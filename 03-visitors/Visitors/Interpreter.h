#pragma once

#include <unordered_map>
#include <fstream>

#include <Visitors/Visitor.h>

class Interpreter: public Visitor {
 public:
  ~Interpreter() override = default;

  void Visit(NumberExpression*) override;
  void Visit(VariableExpression*) override;
  void Visit(AddExpression*) override;
  void Visit(SubExpression*) override;
  void Visit(MulExpression*) override;
  void Visit(DivExpression*) override;
  void Visit(StatementList*) override;
  void Visit(AssignStatement*) override;
  void Visit(DeclarationStatement*) override;
  void Visit(PrintStatement*) override;
  void Visit(Program*) override;

  void SetValue(int value);
  int GetValue() const;

 private:
  std::unordered_map<std::string, int> variables_;
  int value_;
};
