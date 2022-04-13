#include "rass.hpp"

Rass::Rass() {}
Rass::~Rass() {}

void Rass::init(const char *title, int x, int y, int w, int h,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  // Only initialize the needed subsystems to avoid errors
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == 0) {
    // Creates the window
    window = SDL_CreateWindow(title, x, y, w, h, flags);
    // Creates the renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      // Since the game uses a dark color scheme the draw color is set to black
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    isRunning = true;
  }
}

// Clear the renderer
void Rass::clear() { SDL_RenderClear(renderer); }

// Draw everything to the window
void Rass::draw() { SDL_RenderPresent(renderer); }

// Closes SDL alongside the window and renderer
void Rass::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

GameObject* Rass::spawnObject(GameObject* obj) {
  gameObjects.push_back(obj);
  return obj;
}
