#pragma once

#include "rass.hpp"
#include "rass_vector.hpp"

class GameObject {
public:
  // The renderer is only used to load the texture
  GameObject(int x, int y, int w, int h, SDL_Renderer *renderer,
             const char *file);
  virtual ~GameObject(){};
  void updateAccel(Vector *vect);
  void updateVel(Vector *vect);
  void updatePos();
  void changeSize(int w, int h);
  void render(SDL_Renderer *renderer);
  void changeSrc(int x, int y, int w, int h);
  virtual void update(){};
  bool destroy();

protected:
  Vector vel;
  Vector accel;
  bool destroyed = false;
  SDL_Rect srcRect;
  SDL_Rect destRect;
  SDL_Texture *spriteSheet;
};
