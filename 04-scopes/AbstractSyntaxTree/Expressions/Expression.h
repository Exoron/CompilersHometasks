#pragma once

#include <AbstractSyntaxTree/ASTNode.h>

class Expression: public ASTNode {
 public:
  ~Expression() override = default;
};