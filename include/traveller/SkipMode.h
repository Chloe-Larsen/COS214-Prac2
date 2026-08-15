#ifndef SKIP_MODE_H
#define SKIP_MODE_H

#include "TravelMode.h"

class SkipMode : public TravelMode{
public:
    int handle(Terrain *terrain, Traveller* traveller) override;
};


#endif