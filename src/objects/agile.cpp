#include "objects/agile.hpp"
#include "gameVector.hpp"

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

void resolveCollision(const Agile &a, const Agile &b, float &t) {
  Vector relSpeed = a.vel - b.vel;
  if (a.maxp.x <= b.minp.x)
    linesIntersect(a.minp, b.minp - a.size, relSpeed,
                   Vector(0, a.size.y + b.size.y),
                   t); // a rightmost and b leftmost
  if (a.minp.x >= b.maxp.x)
    linesIntersect(a.minp, b.maxp, relSpeed, Vector(0, -a.size.y - b.size.y),
                   t); // a leftmost and b rightmost
  if (a.maxp.y <= b.minp.y)
    linesIntersect(a.minp, b.minp - a.size, relSpeed,
                   Vector(a.size.x + b.size.x, 0),
                   t); // a topmost and b bottommost
  if (a.minp.y >= b.maxp.y)
    linesIntersect(a.minp, b.maxp, relSpeed, Vector(-a.size.x - b.size.x, 0),
                   t); // a bottommost and b topmost
}

uint8_t basicCol(const Agile &a, const Agile &b) {
  uint8_t result = 0b0000;

  if (a.maxp.y >= b.minp.y && a.minp.y <= b.maxp.y) {
    if (a.maxp.x == b.minp.x)
      result |= 0b0001; // right  (1)
    if (a.minp.x == b.maxp.x)
      result |= 0b0100; // left   (4)
  }
  if (a.maxp.x >= b.minp.x && a.minp.x <= b.maxp.x) {
    if (a.maxp.y == b.minp.y)
      result |= 0b0010; // bottom (2)
    if (a.minp.y == b.maxp.y)
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

void Agile::move() {
  float t = 1;
  for (Agile *other : gameObjects) {
    if (*this != *other) {
      uint8_t cols = basicCol(*this, *other);
      if (cols) {
        if (((cols & 1) && (vel.x > 0)) || ((cols & 4) && (vel.x < 0))) {
          vel.x = 0;
        }
        if (((cols & 8) && (vel.y < 0)) || ((cols & 2) && (vel.y > 0))) {
          vel.y = 0;
        }
      } else {
        resolveCollision(*this, *other, t);
      }
    }
  }
  destRect.x += (vel.x * t);
  destRect.y += (vel.y * t);
  *this += (vel * t);
  if (t != 1)
    vel = Vector(0, 0);
}
