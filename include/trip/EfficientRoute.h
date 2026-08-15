#ifndef EFFICIENT_ROUTE_H
#define EFFICIENT_ROUTE_H

#include "Route.h"

class EfficientRoute : public Route
{
public:
    std::vector<Place *> pickPlaces(Location *current, Location *destination) override;
};

#endif