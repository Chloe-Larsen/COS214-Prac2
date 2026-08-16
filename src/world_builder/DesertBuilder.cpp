#include "../../include/world_builder/DesertBuilder.h"

Terrain *DesertBuilder::makeTerrain()
{
    return new DesertTerrain();
}

NPC *DesertBuilder::makeNPC(std::string name)
{
    return new DesertNPC(name);
}

Obstacle *DesertBuilder::makeObstacle(std::string name)
{
    return new DesertObstacle(name);
}