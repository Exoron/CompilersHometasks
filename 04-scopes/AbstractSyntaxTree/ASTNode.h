#pragma once

//#include <Visitors/Visitor.h>
class Visitor;

class ASTNode {
 public:
  virtual ~ASTNode() = default;

  virtual void Accept(Visitor* visitor) = 0;
};
