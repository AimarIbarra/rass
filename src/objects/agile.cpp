#include "objects/agile.hpp"
#include "gameVector.hpp"
#ifdef DEBUG
#include <iostream>
#endif

void Agile::changeAccel(const Vector &accel) {
  vel += accel;
  if (maxVel.x < vel.x)
    vel.x = maxVel.x;
  if (vel.x < -maxVel.x)
    vel.x = -maxVel.x;
  if (maxVel.y < vel.y)
    vel.y = maxVel.y;
  if (vel.y < -maxVel.y)
    vel.y = -maxVel.y;
}

void linesIntersect(const Vector &p, const Vector &q, const Vector &pv,
                    const Vector &qv, float &pt) {
  Vector rv = q - p;

  float n = rv * pv;
  float d = pv * qv;

  float u = n / d;
  float t = rv * qv / d;

  if (t > 0 && t < pt && u > 0 && u < 1) {
    pt = t;
  }
}

void Agile::sweptCols(const AABB *b, const Vector &relSpeed, float &t) {
  if (maxp.x <= b->minp.x)
    linesIntersect(minp, b->minp - size, relSpeed, Vector(0, size.y + b->size.y),
                   t); // a rightmost and b leftmost
  if (minp.x >= b->maxp.x)
    linesIntersect(minp, b->maxp, relSpeed, Vector(0, -size.y - b->size.y),
                   t); // a leftmost and b rightmost
  if (maxp.y <= b->minp.y)
    linesIntersect(minp, b->minp - size, relSpeed, Vector(size.x + b->size.x, 0),
                   t); // a bottommost and b topmost
  if (minp.y >= b->maxp.y)
    linesIntersect(minp, b->maxp, relSpeed, Vector(-size.x - b->size.x, 0),
                   t); // a topmost and b bottommost
}

void Agile::set_col(const AABB *b, int &tar) {
  tar = 0;
  colliding = b->id();
}

void Agile::basicCols(const AABB *b) {
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

void Agile::move() {
  float t = 1;
  for (Agile *other : gameObjects) {
    if (*this == *other)
      continue;
    basicCols(other);
    sweptCols(other, vel - other->vel, t);
  }
  for (AABB *other : terrains) {
    basicCols(other);
#ifdef DEBUG
    std::cout << vel << "\n";
#endif
    sweptCols(other, vel, t);
  }

  Vector adl(floor(vel.x * t), floor(vel.y * t));
  destRect.x += adl.x;
  destRect.y += adl.y;
  *this += adl;

  if (t != 1) {
    vel = Vector(0, 0);
  }
}
