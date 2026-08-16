#ifndef TREASURE_FEATURE_H
#define TREASURE_FEATURE_H

#include "PlaceFeature.h"

class TreasureFeature : public PlaceFeature
{
private:
    int coins;

public:
    TreasureFeature(int coins, Place *place);
    void handleInteraction(Traveller *traveller) override;
    std::map<std::string, PlaceFeature *> getInteractions() override;
    std::vector<Obstacle *> getObstacles() override;
    std::string toString() override;
};

#endif