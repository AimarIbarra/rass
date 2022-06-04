#include "objects/AABB.hpp"

void AABB::sweptCols(const AABB *b, const Vector &relSpeed, float &t) {
  if (maxp.x < b->minp.x)
    Vector::linesIntersect(minp, b->minp - size, relSpeed,
                   Vector(0, size.y + b->size.y),
                   t); // a rightmost and b leftmost
  if (minp.x > b->maxp.x)
    Vector::linesIntersect(minp, b->maxp, relSpeed, Vector(0, -size.y - b->size.y),
                   t); // a leftmost and b rightmost
  if (maxp.y < b->minp.y)
    Vector::linesIntersect(minp, b->minp - size, relSpeed,
                   Vector(size.x + b->size.x, 0),
                   t); // a bottommost and b topmost
  if (minp.y > b->maxp.y)
    Vector::linesIntersect(minp, b->maxp, relSpeed, Vector(-size.x - b->size.x, 0),
                   t); // a topmost and b bottommost
}

void AABB::set_col(AABB *b, int &tar) {
  tar = 0;
  onCols(b);
}

// Even if it looks complicated, it is just a modified
// AABB collision detection and resolution algorithm
void AABB::basicCols(AABB *b, Vector &vel) {
  bool result = 0;
  if ((maxp.y > b->minp.y && minp.y < b->maxp.y) &&
      ((maxp.x == b->minp.x && vel.x > 0) ||
       (minp.x == b->maxp.x && vel.x < 0))) {
    set_col(b, vel.x);
  }
  if (maxp.x > b->minp.x && minp.x < b->maxp.x) {
    if (maxp.y == b->minp.y && vel.y > 0) {
      grounded = 1;
      set_col(b, vel.y);
    }
    if (minp.y == b->maxp.y && vel.y < 0) {
      set_col(b, vel.y);
    }
  }
}
