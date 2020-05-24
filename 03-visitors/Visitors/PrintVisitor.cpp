#include "PrintVisitor.h"
#include "includes.h"

PrintVisitor::PrintVisitor(const std::string& filename): out(filename) {}

void PrintVisitor::PrintTabs() {
  for(int i = 0; i < tabs_; ++i) {
    out << "\t";
  }
}

void PrintVisitor::Visit(NumberExpression* expr) {
  PrintTabs();
  out << "Number" << std::endl;
}

void PrintVisitor::Visit(VariableExpression* expr) {
  PrintTabs();
  out << "Variable" << std::endl;
}

void PrintVisitor::Visit(AddExpression* expr) {
  PrintTabs();
  out << "Add" << std::endl;
  ++tabs_;
  expr->Right()->Accept(this);
  expr->Left()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(SubExpression* expr) {
  PrintTabs();
  out << "Sub" << std::endl;
  ++tabs_;
  expr->Right()->Accept(this);
  expr->Left()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(MulExpression* expr) {
  PrintTabs();
  out << "Mul" << std::endl;
  ++tabs_;
  expr->Right()->Accept(this);
  expr->Left()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(DivExpression* expr) {
  PrintTabs();
  out << "Div" << std::endl;
  ++tabs_;
  expr->Right()->Accept(this);
  expr->Left()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(StatementList* list) {
  PrintTabs();
  out << "Statements" << std::endl;
  ++tabs_;
  for(auto statement: list->Statements()) {
    statement->Accept(this);
  }
  --tabs_;
}

void PrintVisitor::Visit(AssignStatement* assign) {
  PrintTabs();
  out << "Assign" << std::endl;
  ++tabs_;
  assign->Value()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(DeclarationStatement* decl) {
  PrintTabs();
  out << "Decl" << std::endl;
  ++tabs_;
  decl->Value()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(PrintStatement* print) {
  PrintTabs();
  out << "Print" << std::endl;
  ++tabs_;
  print->Value()->Accept(this);
  --tabs_;
}

void PrintVisitor::Visit(Program* program) {
  PrintTabs();
  out << "Program" << std::endl;
  ++tabs_;
  program->List()->Accept(this);
  --tabs_;
}
