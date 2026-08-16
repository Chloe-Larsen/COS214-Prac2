#include "../../include/world_builder/OceanBuilder.h"

Terrain *OceanBuilder::makeTerrain()
{
    return new OceanTerrain();
}

NPC *OceanBuilder::makeNPC(std::string name)
{
    return new OceanNPC(name);
}

Obstacle *OceanBuilder::makeObstacle()
{
    return new OceanObstacle();
}