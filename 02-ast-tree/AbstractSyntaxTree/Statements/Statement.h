#pragma once

#include "../ASTNode.h"

class Statement: public ASTNode {
 public:
  virtual void Execute() = 0;
};
