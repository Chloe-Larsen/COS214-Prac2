#include "../../../include/world_map/place_features/PlaceFeature.h"

PlaceFeature::PlaceFeature(Place *place)
{
    if (place == nullptr)
        throw "Place cannot be null";
    this->place = place;
    place->parent = this;
}

Region *PlaceFeature::getParentNode(bool)
{
    return parent == nullptr ? nullptr : parent->getParentNode(false);
}

Place *PlaceFeature::getCurrentNode()
{
    return place;
}

Terrain *PlaceFeature::getTerrain()
{
    return getCurrentNode()->getTerrain();
}

PlaceFeature::~PlaceFeature()
{
    delete place;
}