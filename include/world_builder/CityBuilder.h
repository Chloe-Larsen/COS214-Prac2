#ifndef CITY_BUILDER_H
#define CITY_BUILDER_H

#include "WorldBuilder.h"
#include "CityNPC.h"
#include "CityObstacle.h"
#include "CityTerrain.h"

class CityBuilder : WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC(std::string name) override;
    Obstacle *makeObstacle(std::string name) override;
};

#endif