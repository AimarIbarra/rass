#include "objects/agile.hpp"
#include "gameVector.hpp"
#ifdef DEBUG
#include "iostream"
#endif

void linesIntersect(const Vector &p, const Vector &q, const Vector &pv,
                    const Vector &qv, float &pt) {
  Vector rv = q - p;

  float n = rv * pv;
  float d = pv * qv;

  float u = n / d;
  float t = rv * qv / d;

  if (t > 0 && t < 1 && u > 0 && u < 1) {
    pt = t;
  }
}

void Agile::resolveCollision(const AABB &b, const Vector &relSpeed, float &t) {
  if (maxp.x <= b.minp.x)
    linesIntersect(minp, b.minp - size, relSpeed, Vector(0, size.y + b.size.y),
                   t); // a rightmost and b leftmost
  if (minp.x >= b.maxp.x)
    linesIntersect(minp, b.maxp, relSpeed, Vector(0, -size.y - b.size.y),
                   t); // a leftmost and b rightmost
  if (maxp.y <= b.minp.y)
    linesIntersect(minp, b.minp - size, relSpeed, Vector(size.x + b.size.x, 0),
                   t); // a bottommost and b topmost
  if (minp.y >= b.maxp.y)
    linesIntersect(minp, b.maxp, relSpeed, Vector(-size.x - b.size.x, 0),
                   t); // a topmost and b bottommost
}

uint8_t Agile::basicCol(const AABB &b) {
  uint8_t result = 0b0000;

  if (maxp.y >= b.minp.y && minp.y <= b.maxp.y) {
    if (maxp.x == b.minp.x)
      result |= 0b0001; // right  (1)
    if (minp.x == b.maxp.x)
      result |= 0b0100; // left   (4)
  }
  if (maxp.x >= b.minp.x && minp.x <= b.maxp.x) {
    if (maxp.y == b.minp.y)
      result |= 0b0010; // bottom (2)
    if (minp.y == b.maxp.y)
      result |= 0b1000; // top    (8)
  }

  return result;
}

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


void Agile::colSolve(const AABB *other, const Vector &relSpeed, float &t) {
  uint8_t cols = basicCol(*other);
  if (cols) {
    if (((cols & 1) && (vel.x > 0)) || ((cols & 4) && (vel.x < 0))) {
      vel.x = 0;
      colliding = other->id();
    }
    if ((cols & 8) && (vel.y < 0)) {
      vel.y = 0;
      colliding = other->id();
    }
    if ((cols & 2) && (vel.y > 0)) {
      grounded = 1;
      vel.y = 0;
      colliding = other->id();
    }
  }

  float tmpT = 1;
  resolveCollision(*other, relSpeed, tmpT);
  if (tmpT < t) {
    t = tmpT;
    colliding = other->id();
  }
}

void Agile::move() {
  grounded = 0;

  float t = 1;
  for (Agile *other : gameObjects) {
    if (*this == *other) continue;
    colSolve(other, vel - other->vel, t);
  }
  for (AABB *other : terrains) {
    colSolve(other, vel, t);
  }

  Vector adl(floor(vel.x * t), floor(vel.y * t));
  destRect.x += adl.x;
  destRect.y += adl.y;
  *this += adl;
  if (t != 1) {
    vel = Vector(0, 0);
  }
}
