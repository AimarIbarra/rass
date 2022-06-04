#include "helpers/assets.hpp"
#include "helpers/texManager.hpp"
#include <filesystem>

std::map<std::string, SDL_Texture *> assets;

void preload(SDL_Renderer *renderer, const char* dir) {
  namespace fs = std::filesystem;

  for (const fs::directory_entry &file :
       fs::recursive_directory_iterator(dir)) {
    if (file.is_directory())
      continue;

    const char* relPath = file.path().c_str();
    std::string path(relPath);
    path.erase(0, strlen(dir) + 1);

    assets[path] = TexManager::loadTexture(relPath, renderer);
  }
}
