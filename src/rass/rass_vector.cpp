#include "rass_vector.hpp"

template <class T> Vector<T>::Vector(T _x, T _y) {
  x = _x;
  y = _y;
}

template <class T> void Vector<T>::sumVector(Vector *vect) {
  x += vect->x;
  y += vect->y;
}

template <class T> void Vector<T>::mulVector(Vector *vect) {
  x *= vect->x;
  y *= vect->y;
}
