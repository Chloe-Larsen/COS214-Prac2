#include "../../include/world_builder/CityBuilder.h"

Terrain *CityBuilder::makeTerrain()
{
    return new CityTerrain();
}

NPC *CityBuilder::makeNPC(std::string name)
{
    return new CityNPC(name);
}

Obstacle *CityBuilder::makeObstacle(std::string name)
{
    return new CityObstacle(name);
}