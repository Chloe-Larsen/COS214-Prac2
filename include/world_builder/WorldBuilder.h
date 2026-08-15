#ifndef WORLD_BUILDER_H
#define WORLD_BUILDER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Terrain.h"
#include "NPC.h"
#include "Obstacle.h"

class WorldBuilder
{
public:
    virtual Terrain *makeTerrain() = 0;
    virtual NPC *makeNPC() = 0;
    virtual Obstacle *makeObstacle() = 0;
    virtual ~WorldBuilder();
};

#endif