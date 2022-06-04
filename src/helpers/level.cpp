#include "helpers/level.hpp"
#include "helpers/objectIds.hpp"
#include "objects/objects.hpp"
#include <fstream>
#include <sstream>

namespace Level {

std::vector<Agile *> agiles;
std::vector<AABB *> boxes;
int requirement = 0;

void load(std::string file) {
  using namespace std;
  ifstream target(file);
  for (string line; getline(target, line);) {
    unsigned int type;
    istringstream iss(line);
    iss >> type;

    switch (type) {
    case TERRAIN_ID: {
      int x, y;
      while (iss >> x >> y)
        boxes.push_back(new Terrain(x, y));
    } break;
    case PLAYER_ID: {
      int x, y;
      while (iss >> x >> y)
        agiles.push_back(new Player(x, y));
    } break;
    case ENEMY_ID: {
      int x, y, dir;
      while (iss >> x >> y >> dir)
        agiles.push_back(new Enemy(x, y, dir));
    } break;
    case COIN_ID: {
      int x, y;
      while (iss >> x >> y)
        boxes.push_back(new Coin(x, y));
    } break;
    }
  }
}

void clear() {
  while(!agiles.empty()) {
    delete agiles[0];
    agiles.erase(agiles.begin());
  }
  while(!boxes.empty()) {
    delete boxes[0];
    boxes.erase(boxes.begin());
  }
}

void tick(SDL_Renderer *renderer) {
  for (unsigned int i = 0; i < agiles.size(); ++i) {
    Agile *obj = agiles[i];
    obj->update();
    if (obj->vel.x || obj->vel.y)
      obj->move();
    if (obj->destroy) {
      delete obj;
      agiles.erase(agiles.begin() + i);
      --i;
      continue;
    }
    obj->render(renderer);
  }
  for (AABB *box : boxes) {
    box->render(renderer);
  }
}

} // namespace Level
