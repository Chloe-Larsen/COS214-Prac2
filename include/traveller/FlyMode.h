#ifndef FLY_MODE_H
#define FLY_MODE_H

#include "TravelMode.h"

class FlyMode : public TravelMode
{
public:
    int handle(Terrain *terrain, Traveller *traveller) override;
};

#endif