#include "../rass.hpp"

void Rass::handleEvents() {
  SDL_Event event;
  // Go to next event
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT: // If the close button is clicked.
    isRunning = false;
    break;
  // The keyboard handling system
  case SDL_KEYDOWN:
  case SDL_KEYUP:
    Keyboard::updateKeys(&event.key);
    break;
  }
}
