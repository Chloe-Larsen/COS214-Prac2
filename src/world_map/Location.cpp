#include "../../include/world_map/Location.h"
#include "../../include/world_map/Region.h"

Location::Location(std::string name)
{
    this->name = name;
}

Place *Location::getParentNode(bool)
{
    return parent->getParentNode(false);
}

Place *Location::getCurrentNode()
{
    return this;
}

/*
    Get terrain of parent Region.
*/
Terrain *Location::getTerrain()
{
    Place *place = getParentNode();

    if (place == nullptr)
    {
        // has no region parent
        return nullptr;
    }

    Region *region = static_cast<Region *>(place); // parent node is guaranteed to be a region
    return region->getTerrain();
}

std::vector<Obstacle *> Location::getObstacles()
{
    return std::vector<Obstacle *>();
}