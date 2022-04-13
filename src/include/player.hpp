#pragma once

#include "assets.hpp"
#include "gameObject.hpp"

class Player : public GameObject {
  int maxX = 15, maxY = 15;
  int velX = 0, velY = 0;
public:
  Player(int x, int y)
      : GameObject(x, y, 32, 32, 0, 0, 0, 0,
                   getTex("assets/images/bot.png")){};
  void move();
  void changeAccel(int x, int y);
  void stop();
  void update();
};
