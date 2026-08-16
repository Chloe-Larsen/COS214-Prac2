#include "../include/GameManager.h"
#include "../include/utils.h"
#include "../include/world_map/Region.h"
#include "../include/trip/EfficientRoute.h"
#include "../include/trip/IndecisiveRoute.h"
#include "../include/trip/ScenicRoute.h"
#include "../include/traveller/WalkMode.h"

#include <iostream>

GameManager::GameManager()
{
    traveller = new Traveller();
    trip = new Trip();

    Region *root = new Region("World", new DesertTerrain());
    map = root;
    Location *tradeCenterLocation = new Location("World Trading Center");
    root->addPlace(tradeCenterLocation);

    Region *desertRegion = new Region("Vast Desert", new DesertTerrain());
    root->addPlace(desertRegion);
    desertRegion->addPlace(new Location("Oasis"));

    Region *cityRegion = new Region("Modern City", new CityTerrain());
    root->addPlace(cityRegion);
    cityRegion->addPlace(new Location("Mall"));
    cityRegion->addPlace(new Location("Park"));

    Region *waterRegion = new Region("Small Lake", new OceanTerrain());
    root->addPlace(waterRegion);
    waterRegion->addPlace(new Location("Warm Water"));
    waterRegion->addPlace(new Location("Cold Water"));
    waterRegion->addPlace(new Location("Frozen Water"));

    startLocation = tradeCenterLocation;
}

GameManager::~GameManager()
{
    delete traveller;
    traveller = nullptr;

    delete trip;
    trip = nullptr;

    delete map;
    map = nullptr;
}

void GameManager::start()
{
    doDestinationLoop();
}

void GameManager::doDestinationLoop()
{
    while (true)
    {

        /* Select Destination Location */

        std::vector<Location *> locations = getLocations(map);
        std::vector<std::string> options;

        for (Location *location : locations)
            options.push_back(location->getName());

        int selectedLocationI = showMenu(
            {"You are currently at " + startLocation->getName() + ".",
             "Select where you want to go next:"},
            options);
        destinationLocation = locations[selectedLocationI - 1];

        /* Select Route */

        int selectedRouteI = showMenu(
            {"You are currently at " + startLocation->getName() + " and you are going to " + destinationLocation->getName() + ".",
             "Select how you would like to get there:"},
            {"Efficiently", "Scenically", "Indecisively"});
        Route *route = nullptr;

        switch (selectedRouteI)
        {
        case 1:
            route = new EfficientRoute();
            break;
        case 2:
            route = new ScenicRoute();
            break;
        case 3:
            route = new IndecisiveRoute();
            break;
        }

        /* Set Up Nested Game Loop */

        std::cout << "a" << std::endl;
        traveller->setTravelMode(new WalkMode());
        std::cout << "b" << std::endl;
        trip->setRoute(route);
        std::cout << "c" << std::endl;
        trip->plan(startLocation, destinationLocation);
        std::cout << "d" << std::endl;
        trip->setCurrentPlaceIndex(0);
        std::cout << "e" << std::endl;

        if (trip->getPlaces().size() <= 1)
        {
            std::cout << "Something went wrong: The trip has less than 2 places." << std::endl;
            return;
        }

        doStepLoop();
    }
}

void GameManager::doStepLoop()
{
    while (true)
    {
        Place *currentPlace = trip->getPlaces()[trip->getCurrentPlaceIndex()]->getCurrentNode();
        Region *currentRegion = nullptr;
        Location *currentLocation = nullptr;

        if (Location *v = dynamic_cast<Location *>(currentPlace))
        {
            currentLocation = v;
            currentRegion = v->getParentNode(true);
        }
        else if (Region *v = dynamic_cast<Region *>(currentPlace))
        {
            currentRegion = v;
        }

        int selectedOption = showMenu(
            {"You are currently " + (currentLocation == nullptr ? "" : "at " + currentLocation->getName()) + " in the " + currentRegion->getName() + " region",
             "Travelling from " +
                 currentLocation->getName() + " to " + destinationLocation->getName() + " via the " + trip->getRoute()->getName() + " route",
             "| Coins: " + std::to_string(traveller->getCoins()) + " | Feathers: " + std::to_string(traveller->getFlightItems()) + " |",
             "Currently " + traveller->getTravelMode()->getName() + " to travel.",
             "What is your next move?"},
            {"Move on",
             "Chill at current place a bit more"
             "Change travel mode",
             "Interact with environment"});

        switch (selectedOption)
        {
        case 1:
            // TODO
            break;
        case 2:
            std::cout << "Nice. Hope you enjoyed a little more rest." << std::endl;
            break;
        case 3:
            // TODO
            break;
        case 4:
            doInteractingLoop();
            break;
        }
    }
}

void GameManager::doInteractingLoop()
{
    while (true)
    {
        Place *currentPlace = trip->getPlaces()[trip->getCurrentPlaceIndex()]->getCurrentNode();
        Region *currentRegion = nullptr;
        Location *currentLocation = nullptr;

        if (Location *v = dynamic_cast<Location *>(currentPlace))
        {
            currentLocation = v;
            currentRegion = v->getParentNode(true);
        }
        else if (Region *v = dynamic_cast<Region *>(currentPlace))
        {
            currentRegion = v;
        }

        std::vector<std::string> options = {"Stop searching (go back)"};
        std::vector<PlaceFeature *> placeFeatures = {};

        for (const auto &entry : currentPlace->getDecorated()->getInteractions())
        {
            options.push_back(entry.first);
            placeFeatures.push_back(entry.second);
        }

        int selectedOption = showMenu(
            {"You are currently " + (currentLocation == nullptr ? "" : "at " + currentLocation->getName()) + " in the " + currentRegion->getName() + " region",
             "| Coins: " + std::to_string(traveller->getCoins()) + " | Feathers: " + std::to_string(traveller->getFlightItems()) + " |",
             "You see a few things around you. What do you do:"},
            options);
        std::cout << "User gave: " << selectedOption << std::endl;

        if (selectedOption == 1)
            break; // go back

        // let feature handle interaction
        placeFeatures[selectedOption - 1]->handleInteraction(traveller);
    }
}

std::vector<Location *> GameManager::getLocations(Place *place)
{
    std::vector<Location *> locations;
    place = place->getCurrentNode();

    if (Region *region = dynamic_cast<Region *>(place))
    {
        for (Place *place : region->getPlaces())
            for (Location *location : getLocations(place))
                locations.push_back(location);
    }
    else if (Location *location = dynamic_cast<Location *>(place))
    {
        locations.push_back(location);
    }

    return locations;
}