#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/AABB.hpp"

class Terrain: public AABB {
public:
  Terrain(int x, int y)
      : GameObject(x, y, 32, 32, 0, 0, 32, 32,
                   assets["terrain.png"]),
        AABB(Vector(x, y), Vector(x, y) + 32) {}
};
