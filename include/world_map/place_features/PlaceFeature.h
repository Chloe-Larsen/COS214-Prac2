#ifndef PLACE_FEATURE_H
#define PLACE_FEATURE_H

#include "../Place.h"

class PlaceFeature : public Place
{
private:
    Place *place;

public:
    PlaceFeature(Place *place);
    Place *getParentNode(bool first) override;
    Place *getCurrentNode() override;
    Terrain *getTerrain() override;
    ~PlaceFeature();
};

#endif