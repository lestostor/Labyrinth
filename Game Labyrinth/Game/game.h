#pragma once
#include "character.h"
#include "map.h"
#include "object.h"
#include "teleport.h"
#include "tvector.h"
#include "wall.h"

class Game {
    Map map;
    Character character;
    TVector<Teleport> teleports;
};