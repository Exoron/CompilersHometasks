#pragma once

#include <Objects/Object.h>

class UninitObject: public Object {
 public:
  int ToInt() override;
};