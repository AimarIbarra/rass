#pragma once
#include "gameObject.hpp"

class Agile: virtual public GameObject {
public:
  Agile(int x, int y){maxX = x; maxY = y;};
  void move();
  void changeAccel(int x, int y);
  void getVel(int &x, int &y);
protected:
  int velY = 0, velX = 0;
  int maxX, maxY;
};
