#pragma once

class ASTNode;

class AST {
 public:
  void Print() const;

 private:
  ASTNode* root_;
};
