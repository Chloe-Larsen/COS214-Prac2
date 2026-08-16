#ifndef SWIM_MODE_H
#define SWIM_MODE_H

#include "TravelMode.h"

class SwimMode : public TravelMode
{
public:
    int handle(Terrain *terrain, Traveller *traveller) override;
};

#endif