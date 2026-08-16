#include "../../include/world_map/Place.h"
#include "../../include/world_map/place_features/PlaceFeature.h"

Place::~Place()
{
    // empty
}

Place *Place::getDecorated()
{
    return dynamic_cast<PlaceFeature *>(parent) ? parent : this;
}