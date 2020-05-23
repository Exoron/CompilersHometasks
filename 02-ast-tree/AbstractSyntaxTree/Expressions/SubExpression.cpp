#include "SubExpression.h"

SubExpression::SubExpression(Expression* left, Expression* right)
    : left_{left}, right_{right} {}

int SubExpression::Eval() { return left_->Eval() - right_->Eval(); }

SubExpression::~SubExpression() {
  delete left_;
  delete right_;
}
