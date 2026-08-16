#ifndef WALK_MODE_H
#define WALK_MODE_H

#include "TravelMode.h"

class WalkMode : public TravelMode
{
public:
    WalkMode();
    int handle(Terrain *terrain, Traveller *traveller) override;
};

#endif