#include "../../../include/world_map/place_features/NpcFeature.h"

NpcFeature::NpcFeature(Place *place, NPC *npc) : PlaceFeature(place)
{
    this->npc = npc;
}

void NpcFeature::handleInteraction(Traveller *traveller)
{
    if (npc->sellsFlightItem())
    {
        std::cout << npc->getName() << " can sell you a feather." << std::endl;
    }
    else
    {
        std::cout << npc->getName() << " says hi!" << std::endl;
    }
}

std::map<std::string, PlaceFeature *> NpcFeature::getInteractions()
{
    std::map<std::string, PlaceFeature *> map = place->getInteractions();
    map["Talk to " + npc->getName()] = this;
    return map;
}

std::vector<Obstacle *> NpcFeature::getObstacles()
{
    return place->getObstacles();
}

NpcFeature::~NpcFeature()
{
    delete npc;
}