#pragma once

#include "gameObject.hpp"
#include "helpers/assets.hpp"
#include "objects/agile.hpp"

class Enemy : public Agile {
public:
  Enemy(int x, int y, int c_dir = 1);
  void update();
  unsigned int id() const {return 2;}
  void onCols(AABB* other);

protected:
  Uint32 m_time;
  int dir;
};
