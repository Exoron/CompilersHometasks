#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* left, Expression* right)
    : left_{left}, right_{right} {}


Expression* BinaryExpression::Left() { return left_; }

Expression* BinaryExpression::Right() { return right_; }