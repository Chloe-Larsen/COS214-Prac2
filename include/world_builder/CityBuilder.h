#ifndef CITY_BUILDER_H
#define CITY_BUILDER_H

#include "WorldBuilder.h"

class CityBuilder : WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC() override;
    Obstacle *makeObstacle() override;    
};

#endif