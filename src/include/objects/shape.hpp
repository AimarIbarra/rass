#pragma once

#include "gameObject.hpp"

class Shape : virtual public GameObject {
public:
  void getDimension(int &x, int &y, int &w, int &h);
};
