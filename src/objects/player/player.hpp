#include "../../rass/gameObject.hpp"

class Player: public GameObject {
public:
  Player(int x, int y, SDL_Renderer *renderer, const char *file)
      : GameObject(x, y, 32, 32, 0, 0, 0, 0, renderer, file){};
  void update();
};
