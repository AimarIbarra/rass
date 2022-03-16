#include "rass/rass.hpp"

Rass *game = nullptr;

int main(int argc, char *args[]) {

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  // Number between 0  and 2³² - 1
  // The frame we are in
  Uint32 initialFrame;

  // The time difference between two frames
  int freeTime;

  game = new Rass();
  game->init("Rassengine", 0, 0, 800, 600, false);

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

  game->clean();

  return 0;
}
