#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>
#include <vector>

// #include "./traveller/Traveller.h"

class GameManager
{
private:
    // Traveller *traveller;
    // Trip *trip;

public:
    void start();
    GameManager();
    ~GameManager();

private:
    void doDestinationLoop();
    void doStepLoop();
    void doInteractingLoop();
    int showMenu(std::vector<std::string> text, std::vector<std::string> options);
};

#endif