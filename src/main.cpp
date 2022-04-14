#include "helpers/helpers.hpp" // Helper functions
#include "objects/objects.hpp" // Custom objects
#include "rass.hpp"

Rass *game = nullptr;

#ifdef __EMSCRIPTEN__
void tick() {
  game->clear();
  game->handleEvents();
  game->update();
  game->draw();
}
#endif

void loadLevel() {
  game->spawnObject(new Player(40, 40));
  game->spawnObject(new Enemy(200, 200));
}

int main(int argc, char *args[]) {
  game = new Rass();
  game->init("Rassengine", 0, 0, 800, 600, false);
  preload(game->rendering(), "assets/images/bot.png");

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(tick, 60, 1);
#else
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  // Number between 0  and 2³² - 1
  // The frame we are in
  Uint32 initialFrame;

  // The time difference between two frames
  int freeTime;

  loadLevel();
  while (game->running()) {
    // The amount of milliseconds that have passed after
    // SDL has been initialized
    initialFrame = SDL_GetTicks();

    game->clear();
    game->handleEvents();
    game->update();
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
