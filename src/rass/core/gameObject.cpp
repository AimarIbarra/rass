#include "gameObject.hpp"
#include <vector>

GameObject::GameObject(int x, int y, int w, int h, int sx, int sy, int sw,
                       int sh, SDL_Texture* texture) {
  destRect = {.x = x, .y = y, .w = w, .h = h};
  srcRect = {.x = sx, .y = sy, .w = sw, .h = sh};
  spriteSheet = texture;
}

void GameObject::render(SDL_Renderer *renderer) {
  SDL_Rect *src;
  srcRect.w == 0 ? src = NULL : src = &srcRect;
  SDL_RenderCopy(renderer, spriteSheet, src, &destRect);
}

bool GameObject::destroy() { return destroyed; }
