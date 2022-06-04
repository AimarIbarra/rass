#include "objects/agile.hpp"
#include "helpers/level.hpp"
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

void Agile::move() {
  grounded = 0;

  float t = 1;
  float tmpT = t;

  for (Agile *other : Level::agiles) {
    if (*this == *other)
      continue;
    basicCols(other, vel);
  }
  for (AABB *other : Level::boxes) {
    basicCols(other, vel);
  }

  AABB* tmpAABB = nullptr;
  for (Agile *other : Level::agiles) {
    if (*this == *other)
      continue;
    sweptCols(other, vel - other->vel, t);
    if (t != tmpT) {
      tmpT = t;
      tmpAABB = other;
    }
  }
  for (AABB *other : Level::boxes) {
    sweptCols(other, vel, t);
    if (t != tmpT) {
      tmpT = t;
      tmpAABB = other;
    }
  }

  if (tmpAABB) onCols(tmpAABB);


  Vector adl(floor(vel.x * t), floor(vel.y * t));
  destRect.x += adl.x;
  destRect.y += adl.y;
  *this += adl;

  if (t != 1)
    vel = Vector(0, 0);
}
