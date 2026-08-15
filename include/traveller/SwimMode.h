#ifndef SWIM_MODE_H
#define SWIM_MODE_H

#include "TravelMode.h"
#include "../world_builder/CityTerrain.h"
#include "../world_builder/DesertTerrain.h"
#include "../world_builder/OceanTerrain.h"

class SwimMode: public TravelMode{
public:
    int handle(Terrain *terrain, Traveller* traveller) override;
};


#endif