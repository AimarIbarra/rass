#pragma once

#ifdef __EMSCRIPTEN__
  #include <emscripten/emscripten.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "keyboard.hpp"
#include "gameObject.hpp"

class Rass {
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;

public:
  Rass();
  ~Rass();

  void init(const char *title, int x, int y, int w, int h, bool fullscreen);

  void handleEvents();
  void clear();
  void draw();
  void clean();

  bool running() { return isRunning; };
  SDL_Renderer* rendering() { return renderer; };
};
