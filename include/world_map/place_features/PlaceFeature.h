#ifndef PLACE_FEATURE_H
#define PLACE_FEATURE_H

#include "../Place.h"
#include "../../traveller/Traveller.h"

class PlaceFeature : public Place
{
protected:
    Place *place;

public:
    PlaceFeature(Place *place);
    virtual void handleInteraction(Traveller *traveller) = 0;
    Region *getParentNode(bool first) override;
    Place *getCurrentNode() override;
    Terrain *getTerrain() override;
    virtual ~PlaceFeature();
};

#endif