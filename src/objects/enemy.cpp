#include "objects/enemy.hpp"
#include <SDL2/SDL_timer.h>

int e_time = SDL_GetTicks() + 1000;
int dir = 1;

void Enemy::update() {
  if (e_time < SDL_GetTicks()) {
    e_time = SDL_GetTicks() + 1000;
    dir *= -1;
  }
  changeAccel(Vector(dir, 0));
  move();
}
