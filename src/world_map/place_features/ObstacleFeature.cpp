#include "../../include/world_map/place_features/ObstacleFeature.h"

ObstacleFeature::ObstacleFeature(Place *place, Obstacle *obstacle) : PlaceFeature(place)
{
    this->obstacle = obstacle;
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