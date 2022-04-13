#include "keyboard.hpp"
#include "player.hpp"
#include <cmath>

void Player::changeAccel(int x, int y) {
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

void Player::move() {
  destRect.x += velX;
  destRect.y += velY;
}

void Player::update() {
  int x = 0, y = 0;
  // X axis checking
  if (Keyboard::getKey(SDL_SCANCODE_A)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_LEFT)->pressed)
    x = -5;
  else if (Keyboard::getKey(SDL_SCANCODE_D)->pressed ||
           Keyboard::getKey(SDL_SCANCODE_RIGHT)->pressed)
    x = 5;
  else
    velX /= 1.1;

  // Y axis checking
  if (Keyboard::getKey(SDL_SCANCODE_W)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_UP)->pressed)
    y = -5;
  else if (Keyboard::getKey(SDL_SCANCODE_S)->pressed ||
           Keyboard::getKey(SDL_SCANCODE_DOWN)->pressed)
    y = 5;
  else
    velY /= 1.1;

  changeAccel(x, y);
  move();
}
