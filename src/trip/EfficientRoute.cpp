#include "../../include/trip/EfficientRoute.h"
#include "../../include/world_map/Region.h"

EfficientRoute::EfficientRoute() : Route("Efficient") {}

std::vector<Place *> EfficientRoute::pickPlaces(Location *current, Location *destination)
{
    // get currents places to root
    Place *currentParent = current->getParentNode();
    std::vector<Place *> finalRoute;
    finalRoute.push_back(current);
    while (currentParent != nullptr)
    {
        finalRoute.push_back(currentParent);
        currentParent = currentParent->getParentNode();
    }

    // get des places to root
    Place *destinationParent = destination->getParentNode();
    std::vector<Place *> destinationRoute;
    destinationRoute.push_back(destination);
    while (destinationParent != nullptr)
    {
        destinationRoute.push_back(destinationParent);
        destinationParent = destinationParent->getParentNode();
    }

    Place *lastMatch;
    // Go till top of the two stacks are not the same
    while (finalRoute.back() == destinationRoute.back())
    {
        lastMatch = finalRoute.back();
        finalRoute.pop_back();
        destinationRoute.pop_back();
    }
    // add last match to the top of the final vector
    finalRoute.push_back(lastMatch);

    // put destination onto final
    while (destinationRoute.size() > 0)
    {
        finalRoute.push_back(destinationRoute.back());
        destinationRoute.pop_back();
    }

    return finalRoute;
}