#include "objects/agile.hpp"
#include "gameVector.hpp"
#include <iostream>

void linesIntersect(const Vector &p, const Vector &q, const Vector &pv, const Vector &qv, float &pt) {
  Vector rv = q - p;

  float n = rv * pv;
  float d = pv * qv;

  float u = n / d;
  float t = rv * qv / d;

  if (t>=0 && t<=1 && u>0 && u<1) {
    std::cout << "Collision happened" << std::endl;
    pt = t;
  }
}

void resolveCollision(const Agile &a, const Agile &b, float &t) {
  Vector relSpeed = a.vel - b.vel;
  if (a.maxp.x <= b.minp.x) linesIntersect(a.minp, b.minp - a.size, relSpeed, Vector(0, a.size.y + b.size.y), t); // a rightmost and b leftmost
  if (a.minp.x >= b.maxp.x) linesIntersect(a.minp, b.maxp, relSpeed, Vector(0, -a.size.y -b.size.y), t); // a leftmost and b rightmost
  if (a.maxp.y <= b.minp.y) linesIntersect(a.minp, b.minp - a.size, relSpeed, Vector(a.size.x + b.size.x, 0), t); // a topmost and b bottommost
  if (a.minp.y >= b.maxp.y) linesIntersect(a.minp, b.maxp, relSpeed, Vector(-a.size.x -b.size.x, 0), t); // a bottommost and b topmost
}

void Agile::changeAccel(const Vector &accel) { vel += accel; if (maxVel.x < vel.x) vel.x = maxVel.x; if (vel.x < -maxVel.x)
    vel.x = -maxVel.x;
  if (maxVel.y < vel.y)
    vel.y = maxVel.y;
  if (vel.y < -maxVel.y)
    vel.y = -maxVel.y;
}

void Agile::move() {
  float t = 1;
  for (Agile* other : gameObjects) {
    if (*this != *other) resolveCollision(*this, *other, t);
  }
  destRect.x += (vel.x*t);
  destRect.y += (vel.y*t);
  *this += (vel*t);
  if (t != 1) vel = Vector(0,0);
}
