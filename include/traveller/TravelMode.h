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
private:
    std::string name;

public:
    TravelMode(std::string name);
    virtual int handle(Terrain *terrain, Traveller *traveller) = 0;
    virtual std::string getName() final;
    virtual ~TravelMode();
};

#endif