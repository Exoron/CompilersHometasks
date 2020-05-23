#pragma once

#include "../ASTNode.h"

class Expression: public ASTNode {
 public:
  virtual int Eval() = 0;
};