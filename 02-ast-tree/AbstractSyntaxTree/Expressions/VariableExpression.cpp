#include "VariableExpression.h"

VariableExpression::VariableExpression(int& var): variable_{var} {}

int VariableExpression::Eval() { return variable_; }