#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"
#include "objects/shape.hpp"

class Player : public Agile, public Shape {
public:
  Player(int x, int y)
      : Agile(15, 15), GameObject(x, y, 32, 32, 0, 0, 0, 0, getTex("assets/images/bot.png")){};
  void update();
};
