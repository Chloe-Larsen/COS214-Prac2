#include "../../include/trip/ScenicRoute.h"

ScenicRoute::ScenicRoute() : Route("indecisive") {}

std::vector<Place *> ScenicRoute::pickPlaces(Location *current, Location *destination)
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

    destinationRoute.pop_back();
    while (destinationRoute.size() > 0)
    {
        finalRoute.push_back(destinationRoute.back());
        destinationRoute.pop_back();
    }
    return finalRoute;
}