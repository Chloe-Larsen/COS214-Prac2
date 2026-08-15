#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Route.h"
#include "../world_map/Place.h"
#include "../world_map/Location.h"

class Route
{
public:
    virtual std::vector<Place *> pickPlaces(Location* current, Location* destination)=0;
    virtual ~Route();
};

#endif