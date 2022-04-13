#pragma once

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_events.h>
#include <map>

// TODO: Add modifiers to the Key object
class Key {
public:
  bool pressed;
};

class Keyboard {
  // The scancode is the same across different keyboards
  static std::map<SDL_Scancode, Key> keys;

public:
  static Key *getKey(SDL_Scancode code);
  static void updateKeys(SDL_KeyboardEvent *key);
};
