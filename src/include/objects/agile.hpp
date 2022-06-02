#pragma once
#include "gameObject.hpp"
#include "physics/vector.hpp"
#include "objects/AABB.hpp"

class Agile: virtual public GameObject, public AABB{
public:
  Agile(const Vector &cminp, const Vector &cmaxp, const Vector &cmax): maxVel(cmax), AABB(cminp, cmaxp){};
  void move();
  void changeAccel(const Vector &accel);
  Vector vel = Vector(0, 0);
  unsigned int colliding = 0;
protected:
  Vector maxVel;
  uint8_t basicCol(const AABB &b);
  void resolveCollision(const AABB &b, const Vector &relSpeed, float &t);
  void colSolve(const AABB *other, const Vector &relSpeed, float &t);
  bool grounded = 0;
};
