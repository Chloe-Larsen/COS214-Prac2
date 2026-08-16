#ifndef SWIM_MODE_H
#define SWIM_MODE_H

#include "TravelMode.h"

class SwimMode : public TravelMode
{
public:
    SwimMode();
    int handle(Terrain *terrain, Traveller *traveller) override;
};

#endif