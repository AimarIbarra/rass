#include "gameObject.hpp"
#include <vector>

std::vector<GameObject*> gameObjects;

GameObject::GameObject(int x, int y, int w, int h, int sx, int sy, int sw,
                       int sh, SDL_Texture* texture) {
  destRect.x = x;
  destRect.y = y;
destRect.w = w;
  destRect.h = h;
  srcRect.x = sx;
  srcRect.y = sy;
  srcRect.w = sw;
  srcRect.h = sh;
  spriteSheet = texture;
}

void GameObject::render(SDL_Renderer *renderer) {
  SDL_Rect *src;
  srcRect.w == 0 ? src = NULL : src = &srcRect;
  SDL_RenderCopy(renderer, spriteSheet, src, &destRect);
}

bool GameObject::destroy() { return destroyed; }
