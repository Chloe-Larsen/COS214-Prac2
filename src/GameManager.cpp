#include "../include/GameManager.h"
#include "../include/utils.h"
#include "../include/world_map/Region.h"
#include "../include/world_map/place_features/NpcFeature.h"
#include "../include/world_map/place_features/ObstacleFeature.h"
#include "../include/world_map/place_features/TreasureFeature.h"
#include "../include/world_builder/CityNPC.h"
#include "../include/world_builder/OceanNPC.h"
#include "../include/world_builder/DesertNPC.h"
#include "../include/world_builder/CityObstacle.h"
#include "../include/world_builder/OceanObstacle.h"
#include "../include/world_builder/DesertObstacle.h"
#include "../include/trip/EfficientRoute.h"
#include "../include/trip/IndecisiveRoute.h"
#include "../include/trip/ScenicRoute.h"
#include "../include/traveller/WalkMode.h"
#include "../include/traveller/SkipMode.h"
#include "../include/traveller/SwimMode.h"
#include "../include/traveller/FlyMode.h"

#include <iostream>

GameManager::GameManager()
{
    traveller = new Traveller();
    traveller->setTravelMode(new WalkMode());

    trip = new Trip();

    Region *worldRegion = new Region("World", new DesertTerrain());
    map = new ObstacleFeature(new DesertObstacle("Tumbleweed"), worldRegion);
    Location *worldTradeCenterLocation = new Location("World Trading Center");
    worldRegion->addPlace(new TreasureFeature(30, worldTradeCenterLocation));

    Region *desertRegion = new Region("Vast Desert", new DesertTerrain());
    worldRegion->addPlace(desertRegion);
    desertRegion->addPlace(new TreasureFeature(300, new NpcFeature(new DesertNPC("Jayden"), new ObstacleFeature(new DesertObstacle("Cactus"), new Location("Oasis")))));

    Region *cityRegion = new Region("Modern City", new CityTerrain());
    desertRegion->addPlace(new NpcFeature(new CityNPC("Sketchy Joe"), new ObstacleFeature(new CityObstacle("Traffic Light"), cityRegion)));
    cityRegion->addPlace(new Location("Mall"));
    cityRegion->addPlace(new TreasureFeature(100, new Location("Park")));

    Region *waterRegion = new Region("Small Lake", new OceanTerrain());
    cityRegion->addPlace(new NpcFeature(new OceanNPC("Fisherman Pete"), waterRegion));
    waterRegion->addPlace(new TreasureFeature(25, new Location("Warm Water")));
    waterRegion->addPlace(new Location("Cold Water"));
    waterRegion->addPlace(new ObstacleFeature(new OceanObstacle("Icicle"), new Location("Frozen Water")));

    startLocation = worldTradeCenterLocation;
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

        options.push_back("Exit Game");
        int selectedLocationI = showMenu(
            {"You are currently at " + startLocation->getName() + ".",
             "Select where you want to go next:"},
            options);

        if (selectedLocationI == options.size())
        {
            std::cout << "Thank you for playing! Goodbye!" << std::endl;
            exit(0);
        }

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

        trip->setRoute(route);
        trip->plan(startLocation, destinationLocation);
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
            currentRegion = v->getParentNode();
        }
        else if (Region *v = dynamic_cast<Region *>(currentPlace))
        {
            currentRegion = v;
        }

        int selectedOption = showMenu(
            {"Travelling from " + startLocation->getName() + " to " + destinationLocation->getName() + " via the " + trip->getRoute()->getName() + " route",
             "You are currently " + (currentLocation == nullptr ? "" : "at " + currentLocation->getName() + " ") + "in the " + currentRegion->getName() + " region (" + currentPlace->getTerrain()->getName() + ")",
             "Currently travelling by " + traveller->getTravelMode()->getName(),
             "| Coins: " + std::to_string(traveller->getCoins()) + " | Feathers: " + std::to_string(traveller->getFlightItems()) + " |",
             "What is your next move?"},
            {"Move on",
             "Change travel mode",
             "Interact with environment"});

        switch (selectedOption)
        {
        case 1:
        {
            // check if already at location
            if (currentLocation == destinationLocation)
            {
                startLocation = destinationLocation;
                destinationLocation = nullptr;
                return; // go back to outer game loop
            }

            // obstacles
            std::vector<Obstacle *> obstacles = currentPlace->getDecorated()->getObstacles();

            if (!obstacles.empty())
            {
                Obstacle *obstacle = obstacles[0];
                int min = 5;
                int max = 100;
                int a = min + (rand() % (max - min + 1));
                int b = min + (rand() % (max - min + 1));
                int answer = a + b;
                std::cout << "On your journey to the next area, you encounter a " << obstacle->getName() << "! For some reason, it's really good at math. To beat it, you must answer its very difficult math question:" << std::endl;
                std::cout << obstacle->getName() << ": What is " << a << " + " << b << "?" << std::endl;

                std::string input;
                std::cin >> input;

                int inputInt = -1;

                try
                {
                    inputInt = std::stoi(input);
                }
                catch (const std::exception &e)
                {
                    // empty
                }

                if (inputInt != answer)
                {
                    std::cout << obstacle->getName() << ": That is incorrect. You ain't going anywhere." << std::endl;
                    break;
                }

                std::cout << obstacle->getName() << ": Okay, you got it. Keep travelling." << std::endl;
            }

            traveller->move(trip, currentPlace->getTerrain());
            break;
        }
        case 2:
        {
            int travelModeI = showMenu(
                {"Select your desired mode of travel:"},
                {"Walking", "Skipping", "Swimming", "Flying"});

            TravelMode *travelMode;

            switch (travelModeI)
            {
            case 1:
                travelMode = new WalkMode();
                break;
            case 2:
                travelMode = new SkipMode();
                break;
            case 3:
                travelMode = new SwimMode();
                break;
            case 4:
                travelMode = new FlyMode();
                break;
            }

            traveller->setTravelMode(travelMode);
            break;
        }
        case 3:
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

        std::vector<std::string> options = {"Stop looking (go back)"};
        std::vector<PlaceFeature *> placeFeatures = {};

        for (const auto &entry : currentPlace->getDecorated()->getInteractions())
        {
            options.push_back(entry.first);
            placeFeatures.push_back(entry.second);
        }

        int selectedOption = showMenu(
            {"You are currently " + (currentLocation == nullptr ? "" : "at " + currentLocation->getName() + " ") + "in the " + currentRegion->getName() + " region (" + currentPlace->getTerrain()->getName() + ")",
             "| Coins: " + std::to_string(traveller->getCoins()) + " | Feathers: " + std::to_string(traveller->getFlightItems()) + " |",
             placeFeatures.empty() ? "You don't see much around you. You should probably stop looking." : "You see a few things around you. What do you do next?"},
            options);

        if (selectedOption == 1)
            break; // go back

        // let feature handle interaction
        placeFeatures[selectedOption - 2]->handleInteraction(traveller);
    }
}

std::vector<Location *> GameManager::getLocations(Place *place)
{
    std::vector<Location *> locations;
    place = place->getCurrentNode();

    if (Region *region = dynamic_cast<Region *>(place))
    {
        for (Place *regionPlace : region->getPlaces())
            for (Location *location : getLocations(regionPlace))
                locations.push_back(location);
    }
    else if (Location *location = dynamic_cast<Location *>(place))
    {
        if (location != startLocation->getCurrentNode())
            locations.push_back(location);
    }

    return locations;
}