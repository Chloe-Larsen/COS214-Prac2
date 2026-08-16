#include "../../../include/world_map/place_features/NpcFeature.h"

NpcFeature::NpcFeature(Place *place, NPC *npc) : PlaceFeature(place)
{
    this->npc = npc;
}

std::vector<Obstacle *> NpcFeature::getObstacles()
{
    return place->getObstacles();
}

NpcFeature::~NpcFeature()
{
    delete npc;
}