#pragma once

class Vector {
public:
  Vector(int cx, int cy);
  int x, y;
  Vector& operator += (const Vector &o);
  friend Vector operator + (Vector v1, const Vector &v2);
  friend Vector operator - (const Vector &v1, const Vector &v2);
  friend int operator * (const Vector &v1, const Vector &v2);
  friend Vector operator * (const Vector &v, float n);
};
