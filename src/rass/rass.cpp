#include "rass.hpp"
#include "rass_gameObject.hpp"
#include "rass_keyboard.hpp"

// TODO: Turn this vector into a member variable
std::vector<GameObject *> gameObjects;

// TODO: Move the GameObject definitions to the game and not the engine
class Player : public GameObject {
public:
  Player(int x, int y, SDL_Renderer *renderer, const char *file)
      : GameObject(x, y, 32, 32, 0, 0, 32, 32, renderer, file){};
  void update() {
    if (Keyboard::getKey(SDL_SCANCODE_A)->pressed ||
        Keyboard::getKey(SDL_SCANCODE_LEFT)->pressed)
      accel.x = -1;
    if (Keyboard::getKey(SDL_SCANCODE_D)->pressed ||
        Keyboard::getKey(SDL_SCANCODE_RIGHT)->pressed)
      accel.x = 1;
    if (Keyboard::getKey(SDL_SCANCODE_W)->pressed ||
        Keyboard::getKey(SDL_SCANCODE_UP)->pressed)
      accel.y = -1;
    if (Keyboard::getKey(SDL_SCANCODE_S)->pressed ||
        Keyboard::getKey(SDL_SCANCODE_DOWN)->pressed)
      accel.y = 1;
  }
};

Rass::Rass() {}
Rass::~Rass() {}

void Rass::init(const char *title, int x, int y, int w, int h,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  // Only initialize the needed subsystems to avoid errors
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == 0) {
    // Creates the window
    window = SDL_CreateWindow(title, x, y, w, h, flags);
    // Creates the renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      // Since the game uses a dark color scheme the draw color is set to black
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    isRunning = true;
  }
  // TODO: Add a level adding function that can be defined in the game files
  // This would be done by adding a function that would change the GameObjects
  // vector
  gameObjects.push_back(new Player(40, 40, renderer, "assets/images/bot.png"));
}

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

void Rass::update() {
  for (int i = 0; i < gameObjects.size(); ++i) {
    if (gameObjects[i]->destroy()) {
      // Delete and erase the Gameobjects set to be destroyed
      delete gameObjects[i];
      gameObjects.erase(gameObjects.begin() + i);
    } else {
      // Update and render all objects that are to be done so
      gameObjects[i]->update();
      gameObjects[i]->updateVel();
      gameObjects[i]->updatePos();
      gameObjects[i]->render(renderer);
    }
  }
}

// Clear the renderer
void Rass::clear() { SDL_RenderClear(renderer); }

// Draw everything to the window
void Rass::draw() { SDL_RenderPresent(renderer); }

// Closes SDL alongside the window and renderer
void Rass::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
