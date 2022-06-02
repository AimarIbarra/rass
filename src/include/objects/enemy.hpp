#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"

class Enemy : public Agile {
public:
  Enemy(int x, int y)
      : GameObject(x, y, 64, 64, 0, 0, 0, 0, getTex("assets/images/bot.png")),
        Agile(Vector(x, y), Vector(x, y) + 64, Vector(15, 15)){};
  void update();
  unsigned int id() const {return 1;}
};
