#include "objects/player.hpp"
#include "keyboard.hpp"
#ifdef DEBUG
#include <iostream>
#endif

void Player::update() {
  int x = 0, y = 0;
  if (Keyboard::getKey(SDL_SCANCODE_A)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_LEFT)->pressed)
    x = -5;
  else if (Keyboard::getKey(SDL_SCANCODE_D)->pressed ||
           Keyboard::getKey(SDL_SCANCODE_RIGHT)->pressed)
    x = 5;
  else
    vel.x /= 1.1;

  if (!grounded) {
    y += 3;
  } else if (Keyboard::getKey(SDL_SCANCODE_W)->pressed ||
             Keyboard::getKey(SDL_SCANCODE_UP)->pressed) {
    y = -30;
  }

  changeAccel(Vector(x, y));
}

bool Player::destroy() {
  if (colliding == 1) return true;
  return false;
}
