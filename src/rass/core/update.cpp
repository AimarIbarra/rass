#include "../rass.hpp"

void Rass::update() {
  for (long unsigned int i = 0; i < gameObjects.size(); ++i) {
    if (gameObjects[i]->destroy()) {
      // Delete and erase the Gameobjects set to be destroyed
      delete gameObjects[i];
      gameObjects.erase(gameObjects.begin() + i);
    } else {
      // Update and render all objects that are to be done so
      gameObjects[i]->update();
      gameObjects[i]->render(renderer);
    }
  }
}
