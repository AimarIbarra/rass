#pragma once
#include "objects/objects.hpp"
#include <SDL_render.h>
#include <vector>
#include <string>

namespace Level {

extern std::vector<Agile *> agiles;
extern std::vector<AABB *> boxes;
extern int requirement;

void tick(SDL_Renderer *renderer);
void load(std::string file);
void clear();

} // namespace Level
