#pragma once

#include "objects/AABB.hpp"

class Coin: public AABB {
public:
  Coin(int x, int y);
  ~Coin();
  unsigned int id() const {return 3;}
};
  
