#pragma once

#include <Visitors/Visitor.h>
#include <fstream>

class PrintVisitor: public Visitor {
 public:
  PrintVisitor(const std::string& filename);
  ~PrintVisitor() override = default;

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

 private:
  void PrintTabs();

 private:
  std::ofstream out;
  int tabs_ = 0;
};
