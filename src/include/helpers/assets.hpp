#pragma once

#include <SDL2/SDL_render.h>
#include <map>
#include <string>

void preload(SDL_Renderer *renderer, const char* dir);
extern std::map<std::string, SDL_Texture *> assets;
