#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"
#include "objects/shape.hpp"

class Enemy : public Shape, public Agile {
public:
  Enemy(int x, int y)
      : GameObject(x, y, 64, 64, 0, 0, 0, 0, getTex("assets/images/bot.png")), Agile(15, 15){};
  void update();
};
