#pragma once

#include <string>
#include "Expression.h"

class VariableExpression: public Expression {
 public:
  explicit VariableExpression(const std::string& name);
  ~VariableExpression() override = default;

  void Accept(Visitor* visitor) override;
  std::string Name() const;

 private:
  const std::string name_;
  //int& variable_; // Invalidation ???
};

