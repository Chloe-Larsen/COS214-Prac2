#ifndef OBSTACLE_FEATURE_H
#define OBSTACLE_FEATURE_H

#include "PlaceFeature.h"

class ObstacleFeature : public PlaceFeature
{
private:
    Obstacle *obstacle;

public:
    ObstacleFeature(Obstacle *obstacle, Place *place);
    void handleInteraction(Traveller *traveller) override;
    std::map<std::string, PlaceFeature *> getInteractions() override;
    std::vector<Obstacle *> getObstacles() override;
    std::string toString() override;
    ~ObstacleFeature();
};

#endif