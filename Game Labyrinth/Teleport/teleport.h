#pragma once
#include "C:/Users/user/Game Labyrinth/Labyrinth/Game Labyrinth/Object/object.h"

class Teleport : public GameObject {
    int _other_x;
    int _other_y;

public:
    Teleport();
    Teleport(const int, const int, const int, const int);
    Teleport(const Teleport&) = default;
};