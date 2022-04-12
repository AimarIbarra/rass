#include "player.hpp"
#include "../../rass/helpers/keyboard.hpp"

void Player::update() {
  if (Keyboard::getKey(SDL_SCANCODE_A)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_LEFT)->pressed)
    destRect.x += -10;
  if (Keyboard::getKey(SDL_SCANCODE_D)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_RIGHT)->pressed)
    destRect.x += 10;
  if (Keyboard::getKey(SDL_SCANCODE_W)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_UP)->pressed)
    destRect.y += -10;
  if (Keyboard::getKey(SDL_SCANCODE_S)->pressed ||
      Keyboard::getKey(SDL_SCANCODE_DOWN)->pressed)
    destRect.y += 10;
}
