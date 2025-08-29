#pragma once

class GameObject {
    int _x;
    int _y;
    bool _walkability;

public:
    GameObject();
    GameObject(const int, const int, const bool);
    GameObject(const GameObject&) = default;
};