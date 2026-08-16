#ifndef PLACE_H
#define PLACE_H

#include <vector>

#include "../world_builder/Obstacle.h"
#include "../world_builder/Terrain.h"

class Place
{
public:
    Place *parent; // automatically set when this object gets added to another place

    virtual Place *getParentNode(bool first = true) = 0; // gets the closest ascendant that is a Region
    virtual Place *getCurrentNode() = 0;                 // returns itself if this object is a Location or Region, otherwise gets the closest descendant that is a Location or Region
    virtual Terrain *getTerrain() = 0;
    // TODO: Map<String, Function(): void> getInteractions()
    virtual std::vector<Obstacle *> getObstacles() = 0;
    virtual ~Place();
};

#endif