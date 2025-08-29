#pragma once
#include "..\Character\character.h"
#include "..\Map\map.h"
#include "..\Teleport\teleport.h"
#include "..\TVector\tvector.h"
#include "..\Wall\wall.h"

class Game {
    Map _map;
    Character _character;
    TVector<Teleport> _teleports;
};