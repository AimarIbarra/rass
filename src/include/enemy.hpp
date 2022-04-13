#pragma once

#include "gameObject.hpp"
#include "assets.hpp"

class Enemy : public GameObject {
public:
  Enemy(int x, int y)
      : GameObject(x, y, 64, 64, 0, 0, 0, 0,
                   getTex("assets/images/bot.png")){};
  void update();
};
