#pragma once

#include "physics/vector.hpp"

class AABB {
public:
  Vector maxp, minp, size;
  AABB(const Vector &cmin, const Vector &cmax): minp(cmin), size(cmax - cmin), maxp(cmax) {};
  friend bool operator != (const AABB &a, const AABB &b) {
    return !(a.minp.x == b.minp.x || a.minp.y == b.minp.y);
  }
  AABB& operator += (const Vector &v) {
    minp += v;
    maxp += v;
    return *this;
  }
};
