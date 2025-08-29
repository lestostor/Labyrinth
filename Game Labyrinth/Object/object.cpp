#include "object.h"
#include "iostream"

GameObject::GameObject() {
    this->_x = 0;
    this->_y = 0;
    this->_walkability = true;
}

GameObject::GameObject(const int x, const int y, const bool walkability) : _x(x), _y(y), _walkability(walkability) {}
