#include "AddExpression.h"

AddExpression::AddExpression(Expression* left, Expression* right)
    : left_{left}, right_{right} {}

int AddExpression::Eval() { return left_->Eval() + right_->Eval(); }

AddExpression::~AddExpression() {
  delete left_;
  delete right_;
}
