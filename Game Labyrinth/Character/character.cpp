#include "character.h"

Character::Character() : GameObject() {}

Character::Character(const int x, const int y) : GameObject(x, y, true) {}