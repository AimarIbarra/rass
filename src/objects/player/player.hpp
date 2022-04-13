#pragma once

#include "../../helpers/assets.hpp"
#include "../../rass/core/gameObject.hpp"

class Player : public GameObject {
public:
  Player(int x, int y)
      : GameObject(x, y, 32, 32, 0, 0, 0, 0,
                   getTex("assets/images/bot.png")){};
  void update();
};
