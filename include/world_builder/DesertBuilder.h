#ifndef DESERT_BUILDER_H
#define DESERT_BUILDER_H

#include "WorldBuilder.h"

class DesertBuilder : WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC() override;
    Obstacle *makeObstacle() override;    
};

#endif