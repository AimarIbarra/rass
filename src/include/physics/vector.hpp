#pragma once
#ifdef DEBUG
#include <ostream>
#endif

class Vector {
public:
  Vector(int cx, int cy);
  int x, y;
  Vector& operator += (const Vector &o);
  Vector& operator += (const int &num);
  friend Vector operator + (Vector v1, const Vector &v2);
  friend Vector operator + (Vector v1, const int &num);
  friend Vector operator - (const Vector &v1, const Vector &v2);
  friend int operator * (const Vector &v1, const Vector &v2);
  friend Vector operator * (const Vector &v, float n);
  static void linesIntersect(const Vector &p, const Vector &q, const Vector &pv, const Vector &qv, float &pt);
#ifdef DEBUG
  friend std::ostream& operator << (std::ostream &os, const Vector &v);
#endif
};
