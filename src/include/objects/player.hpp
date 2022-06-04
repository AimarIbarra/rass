#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"

class Player : public Agile {
public:
  Player(int x, int y)
      : Agile(Vector(x, y), Vector(x, y) + Vector(32, 64), Vector(15, 100)),
      GameObject(x, y, 32, 64, 0, 0, 0, 0, assets["player.png"]){}
  void update();
  void onCols(AABB *other);
  unsigned int id() const {return 1;}
};
