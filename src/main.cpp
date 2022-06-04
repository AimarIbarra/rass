#include "helpers/helpers.hpp" // Helper functions
#include "objects/objects.hpp" // Custom objects
#include "rass.hpp"
#include <string>

#ifdef DEBUG
#include <iostream>
#endif

constexpr int TILE_SIZE = 32;
constexpr int TILE_WIDTH = 24;
constexpr int TILE_HEIGHT = 20;
constexpr int GAME_WIDTH = TILE_SIZE * TILE_WIDTH;
constexpr int GAME_HEIGHT = TILE_SIZE * TILE_HEIGHT;

Rass *game = nullptr;

#ifdef __EMSCRIPTEN__
void tick() {
  game->clear();
  game->handleEvents();
  update();
  game->draw();
}
#endif

void update() {
  static int currentLevel = 0;
  if (Level::requirement < 1) {
    Level::clear();
    Level::load(std::string("assets/levels/") + std::to_string(currentLevel++));
  }
  Level::tick(game->rendering());
}

int main(int argc, char *args[]) {
  game = new Rass();
  game->init("Rassengine", 0, 0, GAME_WIDTH, GAME_HEIGHT, false);

  preload(game->rendering(), "assets/images");
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(tick, 60, 1);
#else

  constexpr int FPS = 60;
  constexpr int frameDelay = 1000 / FPS;

  // Number between 0  and 2³² - 1
  // The frame we are in
  Uint32 initialFrame;

  // The time difference between two frames
  int freeTime;

  while (game->running()) {
    // The amount of milliseconds that have passed after
    // SDL has been initialized
    initialFrame = SDL_GetTicks();

    game->clear();
    game->handleEvents();
    update();
    game->draw();

    freeTime = SDL_GetTicks() - initialFrame;

    // If there are too little seconds before the next update
    // delay by the needed time to do so
    if (frameDelay > freeTime) {
      SDL_Delay(frameDelay - freeTime);
    }
  }
#endif

  game->clean();

  return 0;
}
