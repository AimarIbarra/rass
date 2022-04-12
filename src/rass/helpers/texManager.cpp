#include "texManager.hpp"

SDL_Texture *TexManager::loadTexture(const char *file, SDL_Renderer *renderer) {
  // Load an image (SDL_image needed)
  SDL_Surface *surface = IMG_Load(file);
  // Turn the image into a texture
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  // Destroy the surface
  SDL_FreeSurface(surface);

  return texture;
}
