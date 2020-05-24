#include "SymbolTreeVisitor.h"
#include "includes.h"
#include <SymbolTable/ScopeLayer.h>
#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor()
    : tree_{new ScopeLayer}, current_layer_{tree_.root_} {}

ScopeLayer* SymbolTreeVisitor::GetRoot() {
  return current_layer_;
}

void SymbolTreeVisitor::Visit(NumberExpression*) {}

void SymbolTreeVisitor::Visit(VariableExpression*) {}

void SymbolTreeVisitor::Visit(AddExpression*) {}

void SymbolTreeVisitor::Visit(SubExpression*) {}

void SymbolTreeVisitor::Visit(MulExpression*) {}

void SymbolTreeVisitor::Visit(DivExpression*) {}

void SymbolTreeVisitor::Visit(StatementList* list) {
  for(auto statement: list->Statements()) {
    statement->Accept(this);
  }
}

void SymbolTreeVisitor::Visit(AssignStatement* assign) {}

void SymbolTreeVisitor::Visit(DeclarationStatement* decl) {
  current_layer_->DeclareVariable(Symbol(decl->Name()));
}

void SymbolTreeVisitor::Visit(PrintStatement*) {}

void SymbolTreeVisitor::Visit(Program* program) {
  program->List()->Accept(this);
}

void SymbolTreeVisitor::Visit(ScopeStatementList* scope) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  scope->Statements()->Accept(this);
  current_layer_ = current_layer_->GetParent();
}
