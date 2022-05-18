#include "keyboard.hpp"
#include "objects/player.hpp"

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
    vel.x /= 1.1;

  // Y axis checking
  if (Keyboard::getKey(SDL_SCANCODE_W)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_UP)->pressed)
    y = -5;
  else if (Keyboard::getKey(SDL_SCANCODE_S)->pressed ||
           Keyboard::getKey(SDL_SCANCODE_DOWN)->pressed)
    y = 5;
  else
    vel.y /= 1.1;

  changeAccel(Vector(x, y));
  move();
}
