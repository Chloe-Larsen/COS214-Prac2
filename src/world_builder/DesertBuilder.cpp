#include "../../include/world_builder/DesertBuilder.h"

Terrain *DesertBuilder::makeTerrain()
{
    return new DesertTerrain();
}

NPC *DesertBuilder::makeNPC()
{
    return new DesertNPC();
}

Obstacle *DesertBuilder::makeObstacle()
{
    return new DesertObstacle();
}