#pragma once

#include "Visitor.h"
#include <AbstractSyntaxTree/ASTNode.h>

template<typename T>
class TemplateVisitor : public Visitor {
 public:
  T Accept(ASTNode* element);
 protected:
  T value_;
};

template<typename T>
T TemplateVisitor<T>::Accept(ASTNode * element) {
  element->Accept(this);
  return value_;
}