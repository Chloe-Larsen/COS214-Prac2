#include "../../include/world_builder/CityBuilder.h"

Terrain *CityBuilder::makeTerrain()
{
    return new CityTerrain();
}

NPC *CityBuilder::makeNPC()
{
    return new CityNPC();
}

Obstacle *CityBuilder::makeObstacle()
{
    return new CityObstacle();
}