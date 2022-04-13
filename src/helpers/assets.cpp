#include "assets.hpp"
#include "texManager.hpp"
#include <map>

std::map<const char*, SDL_Texture*> assets;

void preload(SDL_Renderer *renderer, const char *file) {
  assets[file] = TexManager::loadTexture(file, renderer);
}

SDL_Texture* getTex(const char* name) {
  return assets[name];
}
