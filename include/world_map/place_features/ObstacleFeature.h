#ifndef OBSTACLE_FEATURE_H
#define OBSTACLE_FEATURE_H

#include "PlaceFeature.h"

class ObstacleFeature : public PlaceFeature
{
private:
    Obstacle *obstacle;

public:
    ObstacleFeature(Place *place, Obstacle *obstacle);
    // TODO: Map<String, Function(): void> getInteractions()
    std::vector<Obstacle *> getObstacles() override;
    ~ObstacleFeature();
};

#endif