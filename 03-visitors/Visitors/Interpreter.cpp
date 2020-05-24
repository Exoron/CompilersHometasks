#include <iostream>
#include "Interpreter.h"
#include "includes.h"

void Interpreter::Visit(NumberExpression* expr) {
  SetValue(expr->Value());
}

void Interpreter::Visit(VariableExpression* expr) {
  SetValue(variables_[expr->Name()]);
}

void Interpreter::Visit(AddExpression* expr) {
  int value = 0;
  expr->Left()->Accept(this);
  value = GetValue();
  expr->Right()->Accept(this);
  value += GetValue();
  SetValue(value);
}

void Interpreter::Visit(SubExpression* expr) {
  int value = 0;
  expr->Left()->Accept(this);
  value = GetValue();
  expr->Right()->Accept(this);
  value -= GetValue();
  SetValue(value);
}

void Interpreter::Visit(MulExpression* expr) {
  int value = 0;
  expr->Left()->Accept(this);
  value = GetValue();
  expr->Right()->Accept(this);
  value *= GetValue();
  SetValue(value);
}

void Interpreter::Visit(DivExpression* expr) {
  int value = 0;
  expr->Left()->Accept(this);
  value = GetValue();
  expr->Right()->Accept(this);
  value /= GetValue();
  SetValue(value);
}

void Interpreter::Visit(StatementList* list) {
  for(auto statement: list->Statements()) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(AssignStatement* assign) {
  assign->Value()->Accept(this);
  variables_[assign->Name()] = GetValue();
}

void Interpreter::Visit(DeclarationStatement* decl) {
  decl->Value()->Accept(this);
  variables_[decl->Name()] = GetValue();
}

void Interpreter::Visit(PrintStatement* print) {
  print->Value()->Accept(this);
  std::cout << GetValue() << std::endl;
}

void Interpreter::Visit(Program* program) {
  program->List()->Accept(this);
}

void Interpreter::SetValue(int value) {
  value_ = value;
}

int Interpreter::GetValue() const {
  return value_;
}