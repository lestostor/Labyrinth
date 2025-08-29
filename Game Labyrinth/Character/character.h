#pragma once
#include "C:/Users/user/Game Labyrinth/Labyrinth/Game Labyrinth/Object/object.h"

class Character : public GameObject {
public:
    Character();
    Character(const int, const int);
    Character(const Character&) = default;
};