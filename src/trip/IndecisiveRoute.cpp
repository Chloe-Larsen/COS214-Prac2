#include "../../include/trip/IndecisiveRoute.h"

IndecisiveRoute::IndecisiveRoute() : Route("indecisive") {}

std::vector<Place *> IndecisiveRoute::pickPlaces(Location *current, Location *destination)
{
    std::vector<Place *> efficientRoute = getEfficientRoute(current, destination);

    std::vector<Place *> finalRoute;    
    for (size_t i = 0; i < efficientRoute.size() - 1; i++)
    {
        // Add the current node
        finalRoute.push_back(efficientRoute[i]);
        
        // Randomly decide to take a detour        
        if (i % 2 == 1)  // Detour at every other node
        {
            // Wander: go back a few steps, then come forward again
            int wanderSteps = 1 + (i % 3);  // Wander 1-3 steps back
            
            // Go back
            for (int j = 0; j < wanderSteps && i > j; j++)
            {
                finalRoute.push_back(efficientRoute[i - j - 1]);
            }
            
            // Come forward again
            for (int j = wanderSteps - 1; j >= 0 && i > j; j--)
            {
                finalRoute.push_back(efficientRoute[i - j]);
            }
        }
    }
    finalRoute.push_back(efficientRoute.back());

    return finalRoute;
}

std::vector<Place *> IndecisiveRoute::getEfficientRoute(Location *current, Location *destination)
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