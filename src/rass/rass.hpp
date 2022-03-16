#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

class Rass {
  SDL_Window *window;
  SDL_Renderer *renderer;

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

  bool running() { return isRunning; };
};
