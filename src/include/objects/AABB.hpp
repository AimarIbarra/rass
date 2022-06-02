#pragma once

#ifdef DEBUG
#include <ostream>
#endif
#include "physics/vector.hpp"

class AABB {
public:
  Vector maxp, minp, size;
  AABB(const Vector &cmin, const Vector &cmax): minp(cmin), size(cmax - cmin), maxp(cmax) {};
  virtual unsigned int id() const {
    return 0;
  }
  friend bool operator == (const AABB &a, const AABB &b) {
    return a.minp.x == b.minp.x && a.minp.y == b.minp.y;
  }
#ifdef DEBUG
  friend std::ostream& operator << (std::ostream &os, const AABB &box) {
    os << "minp: " << box.minp << ", maxp: " << box.maxp;
    return os;
  }
#endif
  AABB& operator += (const Vector &v) {
    minp += v;
    maxp += v;
    return *this;
  }
};
