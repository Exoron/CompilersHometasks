#include "DivExpression.h"

DivExpression::DivExpression(Expression* left, Expression* right):
  left_{left}, right_{right} {}

int DivExpression::Eval() {
  return left_->Eval() / right_->Eval();
}

DivExpression::~DivExpression() {
  delete left_;
  delete right_;
}
