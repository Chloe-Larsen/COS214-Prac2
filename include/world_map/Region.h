#ifndef REGION_H
#define REGION_H

#include <string>
#include <vector>

#include "Place.h"
#include "../world_builder/Terrain.h"

class Region : public Place
{
private:
    std::string name;
    Terrain *terrain;
    std::vector<Place *> places;

public:
    Region(std::string name, Terrain *terrain);
    void addPlace(Place *place);
    Place *getParentNode(bool first = true) override;
    Place *getCurrentNode() override;
    Terrain *getTerrain() override;
    // TODO: Map<String, Function(): void> getInteractions()
    std::vector<Obstacle *> getObstacles() override;
};

#endif