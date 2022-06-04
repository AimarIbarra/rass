#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

class TexManager {
public:
  static SDL_Texture *loadTexture(const char* file, SDL_Renderer *renderer);
};
