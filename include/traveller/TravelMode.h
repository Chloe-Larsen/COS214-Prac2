#ifndef TRAVEL_MODE_H
#define TRAVEL_MODE_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "../world_map/Place.h"
#include "../world_builder/CityTerrain.h"
#include "../world_builder/DesertTerrain.h"
#include "../world_builder/OceanTerrain.h"

class Traveller;

class TravelMode
{
public:
    virtual int handle(Terrain *terrain, Traveller *traveller) = 0;
    virtual ~TravelMode();
};

#endif