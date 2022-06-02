#include "physics/vector.hpp"

Vector::Vector(int cx, int cy) {
  x = cx; y = cy;
}

Vector& Vector::operator += (const Vector &o) {
  x += o.x;
  y += o.y;
  return *this;
}

Vector& Vector::operator += (const int &num) {
  x += num;
  y += num;
  return *this;
}

Vector operator + (Vector v1, const Vector &v2) {
  v1 += v2;
  return v1;
}

Vector operator + (Vector v1, const int &num) {
  v1 += num;
  return v1;
}

Vector operator - (const Vector &v1, const Vector &v2) {
  return Vector(v1.x - v2.x, v1.y - v2.y);
}

int operator * (const Vector &v1, const Vector &v2) {
  return v1.x * v2.y - v1.y * v2.x;
}

Vector operator * (const Vector &v, float n) {
  return Vector(v.x*n, v.y*n);
}

#ifdef DEBUG
std::ostream& operator << (std::ostream &os, const Vector &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}
#endif
