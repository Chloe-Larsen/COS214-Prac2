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
private:
    std::string name;

public:
    Route(std::string name);
    virtual std::vector<Place *> pickPlaces(Location *current, Location *destination) = 0;
    virtual std::string getName() final;
    virtual ~Route();
};

#endif