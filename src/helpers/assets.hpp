#pragma once

#include <SDL2/SDL_render.h>

void preload(SDL_Renderer* renderer, const char* file);
SDL_Texture* getTex(const char* name);
