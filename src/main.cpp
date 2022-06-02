#include "gameObject.hpp"
#include "helpers/helpers.hpp" // Helper functions
#include "objects/objects.hpp" // Custom objects
#include "rass.hpp"
#include "gameVector.hpp"
#include <vector>

std::vector<Agile*> gameObjects;
std::vector<Terrain*> terrains;

constexpr int GAME_WIDTH = 800;
constexpr int GAME_HEIGHT = 600;

Rass *game = nullptr;

#ifdef __EMSCRIPTEN__
void tick() {
  game->clear();
  game->handleEvents();
  update();
  game->draw();
}
#endif

void setup() {
  preload(game->rendering(), "assets/images/bot.png");
  preload(game->rendering(), "assets/images/player.png");
  preload(game->rendering(), "assets/images/terrain.png");
}

void loadLevel() {
  gameObjects.push_back(new Player(40, 40));
//  gameObjects.push_back(new Enemy(200, 200));
  for (int i = 64; i < GAME_WIDTH - 64; i += 32) {
    terrains.push_back(new Terrain(i, GAME_HEIGHT - 32));
  }
  for (int i = 0; i < GAME_HEIGHT - 64; i += 32) {
    terrains.push_back(new Terrain(GAME_WIDTH - 64, i));
  }
}

void update() {
  for (unsigned int i = 0; i < gameObjects.size(); ++i) {
    Agile* obj = gameObjects[i];
    obj->update();
    if (obj->vel.x || obj->vel.y)
      obj->move();
    if (obj->destroy()) {
      delete obj;
      gameObjects.erase(gameObjects.begin() + i );
    }
    obj->render(game->rendering());
  }
  for (Terrain* ter : terrains) {
    ter->render(game->rendering());
  }
}

int main(int argc, char *args[]) {
  game = new Rass();
  game->init("Rassengine", 0, 0, GAME_WIDTH, GAME_HEIGHT, false);

  setup();

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

  loadLevel();
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
