#ifndef DESERT_BUILDER_H
#define DESERT_BUILDER_H

#include "WorldBuilder.h"
#include "DesertNPC.h"
#include "DesertObstacle.h"
#include "DesertTerrain.h"

class DesertBuilder : public WorldBuilder
{
public:
    Terrain *makeTerrain() override;
    NPC *makeNPC(std::string name) override;
    Obstacle *makeObstacle(std::string name) override;
};

#endif