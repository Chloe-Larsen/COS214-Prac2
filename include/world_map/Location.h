#ifndef LOCATION_H
#define LOCATION_H

#include <string>

#include "Place.h"

class Location : public Place
{
private:
    std::string name;

public:
    Location(std::string name);
    std::string getName();
    Region *getParentNode(bool first = true) override;
    Place *getCurrentNode() override;
    Terrain *getTerrain() override;
    std::map<std::string, PlaceFeature *> getInteractions() override;
    std::vector<Obstacle *> getObstacles() override;
};

#endif