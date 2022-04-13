#pragma once

#include <SDL2/SDL_render.h>

class GameObject {
public:
  // The renderer is only used to load the texture
  GameObject(int x, int y, int w, int h, int sx, int sy, int sw, int sh,
             SDL_Texture* texture);
  virtual ~GameObject(){};
  void changeSize(int w, int h);
  void render(SDL_Renderer *renderer);
  void changeSrc(int x, int y, int w, int h);
  virtual void update(){};
  bool destroy();

protected:
  bool destroyed = false;
  SDL_Rect srcRect;
  SDL_Rect destRect;
  SDL_Texture *spriteSheet;
};