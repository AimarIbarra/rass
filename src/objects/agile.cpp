#include "objects/agile.hpp"

void Agile::changeAccel(int x, int y) {
  velX += x;
  velY += y;
  if (maxX < velX)
    velX = maxX;
  if (velX < -maxX)
    velX = -maxX;
  if (maxY < velY)
    velY = maxY;
  if (velY < -maxY)
    velY = -maxY;
}

void Agile::move() {
  destRect.x += velX;
  destRect.y += velY;
}

void Agile::getVel(int &x, int &y) {
  x = velX;
  y = velY;
}
