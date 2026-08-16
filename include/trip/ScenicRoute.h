#ifndef SCENIC_ROUTE_H
#define SCENIC_ROUTE_H

#include "Route.h"

class ScenicRoute : public Route
{
public:
    ScenicRoute();
    std::vector<Place *> pickPlaces(Location *current, Location *destination) override;
};

#endif