#include "../../include/world_map/place_features/TreasureFeature.h"

TreasureFeature::TreasureFeature(Place *place, int coins) : PlaceFeature(place)
{
    this->coins = coins;
}

std::vector<Obstacle *> TreasureFeature::getObstacles()
{
    return place->getObstacles();
}