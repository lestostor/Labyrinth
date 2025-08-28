#pragma once
#include "tvector.h"
#include "object.h"

class Map {
    int Width;
    int Height;
    TVector<Object> objects;
};