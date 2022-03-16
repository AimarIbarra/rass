#pragma once

template <class T> class Vector {
public:
  Vector(T _x, T _y);
  T x;
  T y;
  void sumVector(Vector *vect);
  void mulVector(Vector *vect);
};
