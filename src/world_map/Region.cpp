#include "../../include/world_map/Region.h"

Region::Region(std::string name, Terrain *terrain)
{
    this->name = name;
    this->terrain = terrain;
}

void Region::addPlace(Place *place)
{
    this->places.push_back(place);
    place->parent = this;
}

Place *Region::getParentNode(bool first)
{
    return first ? parent->getParentNode(false) : this;
}

Place *Region::getCurrentNode()
{
    return this;
}

Terrain *Region::getTerrain()
{
    return terrain;
}

std::vector<Obstacle *> Region::getObstacles()
{
    return std::vector<Obstacle *>();
}