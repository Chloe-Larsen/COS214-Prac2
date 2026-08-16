#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>
#include <vector>

#include "./traveller/Traveller.h"

class GameManager
{
private:
    Traveller *traveller;
    Trip *trip;
    Place *map;
    Location *startLocation;
    Location *destinationLocation;

public:
    void start();
    GameManager();
    ~GameManager();

private:
    void doDestinationLoop();
    void doStepLoop();
    void doInteractingLoop();
    std::vector<Location *> getLocations(Place *place);
};

#endif