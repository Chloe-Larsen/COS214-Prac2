#include <iostream>

#include "./include/GameManager.h"

int main()
{
    std::cout << "Starting game..." << std::endl;

    GameManager *gameManager = new GameManager();

    gameManager->start();

    delete gameManager;

    return 0;
}