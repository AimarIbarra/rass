#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"

class Player : public Agile {
public:
  Player(int x, int y)
      : Agile(Vector(x, y), Vector(x, y) + Vector(32, 32), Vector(15, 15)),
      GameObject(x, y, 32, 32, 0, 0, 0, 0, getTex("assets/images/bot.png")){};
  void update();
};
