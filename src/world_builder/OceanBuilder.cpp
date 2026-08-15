#include "../../include/world_builder/OceanBuilder.h"

Terrain *OceanBuilder::makeTerrain()
{
    return new OceanTerrain();
}

NPC *OceanBuilder::makeNPC()
{
    return new OceanNPC();
}

Obstacle *OceanBuilder::makeObstacle()
{
    return new OceanObstacle();
}