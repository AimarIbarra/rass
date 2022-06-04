#pragma once

#include "physics/vector.hpp"
#include "gameObject.hpp"

class AABB: virtual public GameObject {
public:
  Vector maxp, minp, size;
  AABB(const Vector &cmin, const Vector &cmax): minp(cmin), size(cmax - cmin), maxp(cmax) {};
  virtual unsigned int id() const {
    return 0;
  }
  virtual void onCols(AABB *other){};
  friend bool operator == (const AABB &a, const AABB &b) {
    return a.minp.x == b.minp.x && a.minp.y == b.minp.y;
  }
  AABB& operator += (const Vector &v) {
    minp += v;
    maxp += v;
    return *this;
  }
protected:
  void basicCols(AABB *b, Vector &vel);
  void sweptCols(const AABB *b, const Vector &relSpeed, float &t);
  void set_col(AABB *b, int &tar);
  bool grounded = 0;
};
