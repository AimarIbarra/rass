#include "keyboard.hpp"

// Declare the space in memory for the key map
std::map<SDL_Scancode, Key> Keyboard::keys;

void Keyboard::updateKeys(SDL_KeyboardEvent *key) {
  Key *thisKey = getKey(key->keysym.scancode);
  thisKey->pressed = (key->type != SDL_KEYUP);
}

Key *Keyboard::getKey(SDL_Scancode code) { return &keys[code]; }
