#ifndef TREASURE_FEATURE_H
#define TREASURE_FEATURE_H

#include "PlaceFeature.h"

class TreasureFeature : public PlaceFeature
{
private:
    int coins;

public:
    TreasureFeature(Place *place, int coins);
    // TODO: Map<String, Function(): void> getInteractions()
    std::vector<Obstacle *> getObstacles() override;
};

#endif