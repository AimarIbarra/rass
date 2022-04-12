#pragma once

#ifdef __EMSCRIPTEN__
  #include <emscripten/emscripten.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "gameObject.hpp"
#include "helpers/helpers.hpp"

class Rass {
  SDL_Window *window;
  SDL_Renderer *renderer;
  static std::vector<GameObject *> gameObjects;
  bool isRunning;

public:
  Rass();
  ~Rass();

  void init(const char *title, int x, int y, int w, int h, bool fullscreen);

  void handleEvents();
  void update();
  void clear();
  void draw();
  void clean();

  GameObject* spawnObject(GameObject* obj);

  bool running() { return isRunning; };
  SDL_Renderer* rendering() { return renderer; };
};
