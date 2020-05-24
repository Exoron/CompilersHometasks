#pragma once

#include <Visitors/Visitor.h>
#include <SymbolTable/ScopeLayerTree.h>

class ScopeLayer;
class ScopeLayerTree;

class SymbolTreeVisitor: public Visitor {
 public:
  explicit SymbolTreeVisitor();
  ~SymbolTreeVisitor() override = default;

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

  ScopeLayer* GetRoot();

 private:
  ScopeLayerTree tree_;
  ScopeLayer* current_layer_;
};
