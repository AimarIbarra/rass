#include "rass_gameObject.hpp"
#include "rass_texManager.hpp"

GameObject::GameObject(int x, int y, int w, int h, int sx, int sy, int sw,
                       int sh, SDL_Renderer *renderer, const char *file) {
  destRect.x = x;
  destRect.y = y;
  changeSize(w, h);
  changeSrc(sw, sh, sw, sh);
  spriteSheet = TexManager::loadTexture(file, renderer);
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
