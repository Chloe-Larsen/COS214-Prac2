#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Route.h"
#include "../world_map/Place.h"
#include "../world_map/Location.h"

class Trip
{
private:
    Route *route;
    std::vector<Place *> places;
    int currentPlacesIndex;

public:
    void plan(Location *current, Location *destination);
    void setRoute(Route *route);
    ~Trip();

    // getter and setters
    Route *getRoute();

    std::vector<Place *> getPlaces();

    int getCurrentPlaceIndex();
    void setCurrentPlaceIndex(int index);
};

#endif