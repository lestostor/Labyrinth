#include "teleport.h"

Teleport::Teleport() : GameObject(), _other_x (1), _other_y(1) {}

Teleport::Teleport(const int x, const int y, const int other_x, const int other_y) : GameObject(x, y, true) {
    this->_other_x = other_x;
    this->_other_y = other_y;
}
