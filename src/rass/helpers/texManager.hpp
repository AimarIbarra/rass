#pragma once

#include "../rass.hpp"

class TexManager {
public:
  static SDL_Texture *loadTexture(const char *file, SDL_Renderer *renderer);
};
