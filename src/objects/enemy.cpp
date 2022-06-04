#include "objects/enemy.hpp"
#include <SDL2/SDL_timer.h>

Enemy::Enemy(int x, int y, int c_dir)
    : GameObject(x, y, 64, 64, 0, 0, 0, 0, assets["bot.png"]),
      Agile(Vector(x, y), Vector(x, y) + 64, Vector(10, 15)) {
  dir = c_dir;
}

void Enemy::update() {
  int y = 0;
  if (m_time < SDL_GetTicks()) {
    m_time = SDL_GetTicks() + 700;
    dir *= -1;
  }

  if (!grounded)
    y = 1;

  changeAccel(Vector(dir, y));
}

void Enemy::onCols(AABB *other) {
  if (other->id() == 1)
    other->destroy = true;
}
