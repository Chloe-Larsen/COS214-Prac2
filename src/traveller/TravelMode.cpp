#include "../../include/traveller/TravelMode.h"

TravelMode::TravelMode(std::string name)
{
    this->name = name;
}

std::string TravelMode::getName()
{
    return name;
}

TravelMode::~TravelMode()
{
}