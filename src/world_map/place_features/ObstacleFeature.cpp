#include "../../../include/world_map/place_features/ObstacleFeature.h"

ObstacleFeature::ObstacleFeature(Place *place, Obstacle *obstacle) : PlaceFeature(place)
{
    this->obstacle = obstacle;
}

void ObstacleFeature::handleInteraction(Traveller *traveller)
{
    throw "Unexpected method call";
}

std::map<std::string, PlaceFeature *> ObstacleFeature::getInteractions()
{
    return place->getInteractions();
}

std::vector<Obstacle *> ObstacleFeature::getObstacles()
{
    std::vector<Obstacle *> v = place->getObstacles();
    v.push_back(obstacle); // add own obstacle
    return v;
}

ObstacleFeature::~ObstacleFeature()
{
    delete obstacle;
}