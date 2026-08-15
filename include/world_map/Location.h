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
    Place *getParentNode(bool first = true) override;
    Place *getCurrentNode() override;
    Terrain *getTerrain() override;
    // TODO: Map<String, Function(): void> getInteractions()
    std::vector<Obstacle *> getObstacles() override;
};

#endif