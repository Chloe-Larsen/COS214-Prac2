#include "../include/GameManager.h"
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

    currentLocation = tradeCenterLocation;
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
            {"You are currently at " + currentLocation->getName() + ".",
             "Select where you want to go next:"},
            options);
        destinationLocation = locations[selectedLocationI - 1];

        /* Select Route */

        int selectedRouteI = showMenu(
            {"You are currently at " + currentLocation->getName() + " and you are going to " + destinationLocation->getName() + ".",
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

        traveller->setTravelMode(new WalkMode());
        trip->setRoute(route);
        trip->plan(currentLocation, destinationLocation);
        trip->setCurrentPlaceIndex(0);

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
             "Change travel mode",
             "Interact with environment"});
        std::cout << "User gave: " << selectedOption << std::endl;
    }
}

void GameManager::doInteractingLoop()
{
}

int GameManager::showMenu(std::vector<std::string> text, std::vector<std::string> options)
{
    bool firstAttempt = true;

    while (true)
    {
        std::string toShow = "\n========================================\n";

        if (!firstAttempt)
            toShow += "\nThat isn't an option! Try again. Type in 1-" + std::to_string(options.size()) + "\n";

        for (std::size_t i = 0; i < text.size(); i++)
            toShow += "\n" + text[i];

        toShow += '\n';

        for (std::size_t i = 0; i < options.size(); i++)
            toShow += "\n" + std::to_string(i + 1) + ") " + options[i];

        std::string input;

        std::cout << toShow << '\n'
                  << std::endl;
        std::cin >> input;

        int selected = -1;

        try
        {
            selected = std::stoi(input);
        }
        catch (const std::exception &e)
        {
            // empty
        }

        if (selected >= 1 && selected <= static_cast<int>(options.size()))
            return selected;

        firstAttempt = false;
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