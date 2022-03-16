#include "rass_gameObject.hpp"
#include "rass_texManager.hpp"

GameObject::GameObject(int x, int y, int w, int h, SDL_Renderer *renderer,
                       const char *file) {
  changePosition(x, y);
  changeSize(w, h);
  changeSrc(0, 0, w, h);
  spriteSheet = TexManager::loadTexture(file, renderer);
}

void GameObject::updateAccel(Vector *vect) {
  accel.x += vect->x;
  accel.y += vect->y;
  delete vect;
}

void GameObject::updateVel(Vector *vect) {
  vel.x += vect->x;
  vel.y += vect->y;
  delete vect;
}

void GameObject::updatePos() {
  destRect.x += vel.x;
  destRect.y += vel.y;
}

void GameObject::changeSize(int w, int h) {
  destRect.w = w;
  destRect.h = h;
}

void GameObject::changeSrc(int x, int y, int w, int h) {
  srcRect.x = x;
  srcRect.y = y;
  srcRect.w = w;
  srcRect.h = h;
}

void GameObject::render(SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, spriteSheet, &srcRect, &destRect);
}

bool GameObject::destroy() { return destroyed; }
