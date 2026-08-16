#ifndef INDECISIVE_ROUTE_H
#define INDECISIVE_ROUTE_H

#include "Route.h"

class IndecisiveRoute : public Route
{
public:
    IndecisiveRoute();
    std::vector<Place *> pickPlaces(Location *current, Location *destination) override;
};

#endif