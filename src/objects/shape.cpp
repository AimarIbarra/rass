#include "objects/shape.hpp"
void Shape::getDimension(int &x, int &y, int &w, int &h) {
  x = destRect.x;
  y = destRect.y;
  w = destRect.w;
  h = destRect.h;
}
