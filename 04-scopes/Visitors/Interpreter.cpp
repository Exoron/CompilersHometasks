#include <iostream>
#include "Interpreter.h"
#include "includes.h"
#include <SymbolTable/ScopeLayer.h>
#include <Objects/Integer.h>
#include <Objects/UninitObject.h>

Interpreter::Interpreter(ScopeLayer* root): current_layer_{root} {
  offsets_.push(0);
}

void Interpreter::Visit(NumberExpression* expr) {
  SetValue(expr->Value());
}

void Interpreter::Visit(VariableExpression* expr) {
  SetValue(current_layer_->Get(expr->Name())->ToInt());
}

void Interpreter::Visit(AddExpression* expr) {
  int value = Accept(expr->Left()) + Accept(expr->Right());
  SetValue(value);
}

void Interpreter::Visit(SubExpression* expr) {
  int value = Accept(expr->Left()) - Accept(expr->Right());
  SetValue(value);
}

void Interpreter::Visit(MulExpression* expr) {
  int value = Accept(expr->Left()) * Accept(expr->Right());
  SetValue(value);
}

void Interpreter::Visit(DivExpression* expr) {
  int value = Accept(expr->Left()) / Accept(expr->Right());
  SetValue(value);
}

void Interpreter::Visit(StatementList* list) {
  for(auto statement: list->Statements()) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(AssignStatement* assign) {
  int value = Accept(assign->Value());
  current_layer_->Put(assign->Name(), std::make_shared<Integer>(value));
}

void Interpreter::Visit(DeclarationStatement* decl) {
  //std::cerr << "Var decl" << std::endl;
  Expression* expr = decl->Value();
  if(expr == nullptr) {
    current_layer_->Put(decl->Name(), std::make_shared<UninitObject>());
  } else {
    int value = Accept(expr);
    current_layer_->Put(decl->Name(), std::make_shared<Integer>(value));
  }
}

void Interpreter::Visit(PrintStatement* print) {
  std::cout << Accept(print->Value()) << std::endl;
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

void Interpreter::Visit(ScopeStatementList* scope) {
  int index = offsets_.top();
  current_layer_ = current_layer_->GetChild(index);
  offsets_.push(0);
  //std::cerr << "Entering the scope" << std::endl;
  scope->Statements()->Accept(this);
  //std::cerr << "Leaving the scope" << std::endl;
  offsets_.pop();

  offsets_.pop();
  offsets_.push(index + 1);

  current_layer_ = current_layer_->GetParent();
}
