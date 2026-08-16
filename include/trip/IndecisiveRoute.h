#ifndef INDECISIVE_ROUTE_H
#define INDECISIVE_ROUTE_H

#include "Route.h"

class IndecisiveRoute : public Route
{
private:
    std::vector<Place *> getEfficientRoute(Location *current, Location *destination);
public:
    IndecisiveRoute();
    std::vector<Place *> pickPlaces(Location *current, Location *destination) override;
};

#endif