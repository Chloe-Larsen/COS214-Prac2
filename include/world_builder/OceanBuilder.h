#ifndef OCEAN_BUILDER_H
#define OCEAN_BUILDER_H

#include "WorldBuilder.h"

class OceanBuilder : WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC() override;
    Obstacle *makeObstacle() override;    
};

#endif