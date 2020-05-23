#include "MulExpression.h"

MulExpression::MulExpression(Expression* left, Expression* right):
  left_{left}, right_{right} {}

int MulExpression::Eval() {
  return left_->Eval() * right_->Eval();
}

MulExpression::~MulExpression() {
  delete left_;
  delete right_;
}
