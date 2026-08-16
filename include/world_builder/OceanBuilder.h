#ifndef OCEAN_BUILDER_H
#define OCEAN_BUILDER_H

#include "WorldBuilder.h"
#include "OceanNPC.h"
#include "OceanObstacle.h"
#include "OceanTerrain.h"

class OceanBuilder : WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC(std::string name) override;
    Obstacle *makeObstacle(std::string name) override;    
};

#endif