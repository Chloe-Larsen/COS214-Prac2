#include "../../include/world_map/Region.h"

Region::Region(std::string name, Terrain *terrain)
{
    this->name = name;
    this->terrain = terrain;
}

Region::~Region()
{
    for (Place *place : places)
        delete place;
}

std::string Region::getName()
{
    return name;
}

void Region::addPlace(Place *place)
{
    this->places.push_back(place);
    place->parent = this;
}

std::vector<Place *> Region::getPlaces()
{
    return places;
}

Region *Region::getParentNode(bool first)
{
    if (!first)
        return this;
    return parent == nullptr ? nullptr : parent->getParentNode(false);
}

Place *Region::getCurrentNode()
{
    return this;
}

Terrain *Region::getTerrain()
{
    return terrain;
}

std::map<std::string, PlaceFeature *> Region::getInteractions()
{
    return {};
}

std::vector<Obstacle *> Region::getObstacles()
{
    return std::vector<Obstacle *>();
}