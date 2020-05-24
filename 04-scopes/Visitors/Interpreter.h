#pragma once

#include <stack>
#include <unordered_map>
#include <fstream>

#include <Visitors/TemplateVisitor.h>

class ScopeLayer;

class Interpreter: public TemplateVisitor<int> {
 public:
  Interpreter(ScopeLayer* root);
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
  void Visit(ScopeStatementList*) override;

  void SetValue(int value);
  int GetValue() const;

 private:
  ScopeLayer* current_layer_;
  std::stack<int> offsets_;
  //std::unordered_map<std::string, int> variables_;
};
