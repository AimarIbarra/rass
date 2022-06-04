#include "objects/coin.hpp"
#include "helpers/level.hpp"
#include "physics/vector.hpp"
#include "helpers/assets.hpp"

#include <iostream>

Coin::Coin(int x, int y)
    : AABB(Vector(x, y), Vector(x, y) + 32),
      GameObject(x, y, 32, 32, 0, 0, 0, 0, assets["coin.png"]) {
  ++Level::requirement;
}

Coin::~Coin() { --Level::requirement; }
