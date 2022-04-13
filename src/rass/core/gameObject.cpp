#include "gameObject.hpp"

GameObject::GameObject(int x, int y, int w, int h, int sx, int sy, int sw,
                       int sh, SDL_Texture* texture) {
  destRect.x = x;
  destRect.y = y;
  changeSize(w, h);
  changeSrc(sw, sh, sw, sh);
  spriteSheet = texture;
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
  SDL_Rect *test;
  srcRect.w == 0 ? test = NULL : test = &srcRect;
  SDL_RenderCopy(renderer, spriteSheet, test, &destRect);
}

bool GameObject::destroy() { return destroyed; }
