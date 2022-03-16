#pragma once

#include "rass.hpp"

class GameObject {
public:
  // The renderer is only used to load the texture
  GameObject(int x, int y, int w, int h, SDL_Renderer *renderer,
             const char *file);
  virtual ~GameObject(){};
  // TODO: Instead of taking two parameters take a Vector and a cap
  // TODO: Change aceleration and velocity instead of pos
  // The function should add the given Vector to the aceleration
  // after that add the acceleration to the speed
  // TODO: Implement speed addition with a cap
  // then delete the given Vector
  void changePosition(int x, int y);
  // TODO: updatePos()
  // Add the speed to destRect
  void changeSize(int w, int h);
  void render(SDL_Renderer *renderer);
  void changeSrc(int x, int y, int w, int h);
  virtual void update(){};
  bool destroy();

protected:
  // TODO: Floating speed
  // TODO: Floating acceleration
  bool destroyed = false;
  SDL_Rect srcRect;
  SDL_Rect destRect;
  SDL_Texture *spriteSheet;
};
