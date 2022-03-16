#include "rass_gameObject.hpp"
#include "rass_texManager.hpp"

GameObject::GameObject(int x, int y, int w, int h, SDL_Renderer *renderer,
                       const char *file) {
  changePosition(x, y);
  changeSize(w, h);
  changeSrc(0, 0, w, h);
  spriteSheet = TexManager::loadTexture(file, renderer);
}

// TODO: Take a Vector instead of two parameters
// TODO: Change aceleration instead of position
void GameObject::changePosition(int x, int y) {
  destRect.x = x;
  destRect.y = y;
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
