#include "rass_vector.hpp"

void Vector::sumVector(Vector *vect) {
  x += vect->x;
  y += vect->y;
}

void Vector::mulVector(Vector *vect) {
  x *= vect->x;
  y += vect->y;
}

void Vector::subVector(Vector *vect) {
  x -= vect->x;
  y -= vect->y;
}

void Vector::divVector(Vector *vect) {
  x /= vect->x;
  y /= vect->y;
}
