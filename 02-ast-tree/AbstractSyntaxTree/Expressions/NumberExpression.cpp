#include "NumberExpression.h"

NumberExpression::NumberExpression(int n): value_{n} {}

int NumberExpression::Eval() {
  return value_;
}