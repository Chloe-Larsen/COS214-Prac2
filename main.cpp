#include <iostream>

#include "./include/GameManager.h"
#include "./include/traveller/FlyMode.h"
#include "./include/traveller/SkipMode.h"
#include "./include/traveller/SwimMode.h"
#include "./include/traveller/WalkMode.h"
#include "./include/world_builder/CityBuilder.h"
#include "./include/world_builder/DesertBuilder.h"
#include "./include/world_builder/OceanBuilder.h"
#include "./include/world_builder/WorldBuilder.h"
#include "../include/trip/EfficientRoute.h"
#include "../include/trip/IndecisiveRoute.h"
#include "../include/trip/ScenicRoute.h"
#include "../include/utils.h"
#include "../include/world_map/Region.h"
#include "../include/world_map/place_features/NpcFeature.h"
#include "../include/world_map/place_features/ObstacleFeature.h"
#include "../include/world_map/place_features/TreasureFeature.h"

void playGame()
{
    std::cout << "Starting game..." << std::endl;

    GameManager *gameManager = new GameManager();

    gameManager->start();

    delete gameManager;
}

void testMapCreation()
{
    GameManager *gm = new GameManager(); // creates map in constructor
    std::cout << "Map: " << gm->getMap()->toString() << std::endl;
    delete gm;
}

void testMoving()
{
    Trip *trip = new Trip();
    Terrain *tc = new CityTerrain();
    Terrain *td = new DesertTerrain();
    Terrain *to = new OceanTerrain();

    Traveller *trav = new Traveller();
    trav->getCoins();
    trav->setCoins(300);
    trav->getFlightItems();

    trav->setTravelMode(new WalkMode());
    trav->move(trip, tc);
    trav->move(trip, td);
    trav->move(trip, to);

    trav->setTravelMode(new SkipMode());
    trav->move(trip, tc);
    trav->move(trip, td);
    trav->move(trip, to);

    trav->setTravelMode(new SwimMode());
    trav->move(trip, tc);
    trav->move(trip, td);
    trav->move(trip, to);

    trav->setTravelMode(new FlyMode());
    trav->move(trip, tc);
    trav->move(trip, td);
    trav->move(trip, to);
    trav->setFlightItems(10);
    trav->move(trip, tc);
    trav->move(trip, td);
    trav->move(trip, to);

    delete trip;
    delete tc;
    delete td;
    delete to;
    delete trav;

    TravelMode *abc = new WalkMode();
    abc->getName();
    delete abc;
}

void testRoutes()
{
    WorldBuilder *cityBuilder = new CityBuilder();
    WorldBuilder *desertBuilder = new DesertBuilder();
    WorldBuilder *oceanBuilder = new OceanBuilder();

    Place *map = nullptr;

    Region *worldRegion = new Region("World", desertBuilder->makeTerrain());
    map = new ObstacleFeature(desertBuilder->makeObstacle("Tumbleweed"), worldRegion);
    Location *worldTradeCenterLocation = new Location("World Trading Center");
    worldRegion->addPlace(new TreasureFeature(30, worldTradeCenterLocation));

    Region *desertRegion = new Region("Vast Desert", desertBuilder->makeTerrain());
    worldRegion->addPlace(desertRegion);
    desertRegion->addPlace(new TreasureFeature(300, new NpcFeature(desertBuilder->makeNPC("Jayden"), new ObstacleFeature(desertBuilder->makeObstacle("Cactus"), new Location("Oasis")))));

    Region *cityRegion = new Region("Modern City", cityBuilder->makeTerrain());
    desertRegion->addPlace(new NpcFeature(cityBuilder->makeNPC("Sketchy Joe"), new ObstacleFeature(cityBuilder->makeObstacle("Traffic Light"), cityRegion)));
    cityRegion->addPlace(new Location("Mall"));
    cityRegion->addPlace(new TreasureFeature(100, new Location("Park")));

    Region *waterRegion = new Region("Small Lake", oceanBuilder->makeTerrain());
    cityRegion->addPlace(new NpcFeature(oceanBuilder->makeNPC("Fisherman Pete"), waterRegion));
    waterRegion->addPlace(new TreasureFeature(25, new Location("Warm Water")));
    Location *coldWaterLocation = new Location("Cold Water");
    waterRegion->addPlace(coldWaterLocation);
    waterRegion->addPlace(new ObstacleFeature(oceanBuilder->makeObstacle("Icicle"), new Location("Frozen Water")));

    delete cityBuilder;
    delete desertBuilder;
    delete oceanBuilder;

    Location *startLoc = worldTradeCenterLocation;
    Location *destinationLoc = coldWaterLocation;

    Trip *trip = new Trip();

    trip->setRoute(new EfficientRoute());
    trip->plan(startLoc, destinationLoc);
    trip->setRoute(new ScenicRoute());
    trip->plan(startLoc, destinationLoc);
    trip->setRoute(new IndecisiveRoute());
    trip->plan(startLoc, destinationLoc);

    trip->getPlaces();
    trip->setCurrentPlaceIndex(1);
    trip->getCurrentPlaceIndex();

    delete map;
    delete trip;
}

void testPlaceFeatures()
{
    PlaceFeature *n = new NpcFeature(new OceanNPC("Guy"), new Location("Some place"));
    n->toString();
    n->getInteractions();
    n->getObstacles();
    delete n;

    n = new ObstacleFeature(new OceanObstacle("Thing"), new Location("Some place"));
    n->toString();
    n->getInteractions();
    n->getObstacles();
    delete n;

    n = new TreasureFeature(100, new Location("Some place"));
    n->toString();
    n->getInteractions();
    n->getObstacles();
    delete n;
}

void testNpcs()
{
    NPC *c = new CityNPC("Guy");
    c->sellsFlightItem();
    delete c;
    c = new DesertNPC("Guy");
    c->sellsFlightItem();
    delete c;
    c = new OceanNPC("Guy");
    c->sellsFlightItem();
    delete c;
}

void testPlaces()
{
    Place *p = new Region("Some place", new DesertTerrain());
    static_cast<Region *>(p)->getPlaces();
    static_cast<Region *>(p)->getName();
    p->getParentNode(true);
    p->getParentNode(false);
    p->getCurrentNode();
    p->getTerrain();
    p->getInteractions();
    p->getObstacles();
    p->toString();
    delete p;

    p = new Location("Some place");
    p->getParentNode(true);
    p->getParentNode(false);
    p->getCurrentNode();
    p->getTerrain();
    p->getInteractions();
    p->getObstacles();
    p->toString();
    delete p;

    p = new NpcFeature(new DesertNPC("Guy"), new Location("Some place"));
    p->getParentNode(true);
    p->getParentNode(false);
    p->getCurrentNode();
    p->getTerrain();
    p->getInteractions();
    p->getObstacles();
    p->toString();
    delete p;

    p = new ObstacleFeature(new DesertObstacle("Thing"), new Location("Some place"));
    p->getParentNode(true);
    p->getParentNode(false);
    p->getCurrentNode();
    p->getTerrain();
    p->getInteractions();
    p->getObstacles();
    p->toString();
    delete p;

    p = new TreasureFeature(100, new Location("Some place"));
    p->getParentNode(true);
    p->getParentNode(false);
    p->getCurrentNode();
    p->getTerrain();
    p->getInteractions();
    p->getObstacles();
    p->toString();
    delete p;
}

void testObstacle()
{
    Obstacle *o = new DesertObstacle("Thing");
    o->getName();
    delete o;
}

void test()
{
    std::cout << "Starting testing..." << std::endl;

    std::cout << "Testing map creation..." << std::endl;
    testMapCreation();
    std::cout << "Testing moving..." << std::endl;
    testMoving();
    std::cout << "Testing routes..." << std::endl;
    testRoutes();
    std::cout << "Testing place features..." << std::endl;
    testPlaceFeatures();
    std::cout << "Testing NPCs..." << std::endl;
    testNpcs();
    std::cout << "Testing places..." << std::endl;
    testPlaces();
    std::cout << "Testing obstacle..." << std::endl;
    testObstacle();

    std::cout << "Testing finished." << std::endl;
}

int main()
{
    bool testing = true;

    if (testing)
    {
        test();
    }
    else
    {
        playGame();
    }

    return 0;
}