#include "../../include/world_builder/Obstacle.h"

Obstacle::Obstacle(std::string name)
{
    this->name = name;
}

std::string Obstacle::getName()
{
    return name;
}

Obstacle::~Obstacle()
{
    // empty
}