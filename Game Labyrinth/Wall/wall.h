#pragma once
#include "C:/Users/user/Game Labyrinth/Labyrinth/Game Labyrinth/Object/object.h"

class Wall : public GameObject {
public:
    Wall();
    Wall(const int, const int);
    Wall(const Wall&) = default;
};