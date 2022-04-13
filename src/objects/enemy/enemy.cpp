#include "enemy.hpp"
#include <SDL2/SDL_timer.h>

int time = SDL_GetTicks() + 1000;
int dir = 1;

void Enemy::update() {
  if (time < SDL_GetTicks()) {
    time = SDL_GetTicks() + 1000;
    dir *= -1;
  }
  destRect.x += 5 * dir;
}
