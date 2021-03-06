#pragma once

#include <Objects/Object.h>

class Integer: public Object {
 public:
  explicit Integer(int value);
  int ToInt() override;
 private:
  int value_;
};