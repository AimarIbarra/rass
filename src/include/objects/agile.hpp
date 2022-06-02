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
  void set_col(const AABB *b, int &tar);
protected:
  unsigned int colliding = 0;
  Vector maxVel;
  void basicCols(const AABB *b);
  void sweptCols(const AABB *b, const Vector &relSpeed, float &t);
  bool grounded = 0;
};
