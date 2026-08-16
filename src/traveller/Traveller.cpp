#include "../../include/traveller/Traveller.h"

void Traveller::move(Trip *trip, Terrain *terrain)
{
    int amount = travelMode->handle(terrain, this);
    int currentIndex = trip->getCurrentPlaceIndex();
    int size = (trip->getPlaces()).size();
    int newIndex = ((currentIndex + amount) >= size) ? size - 1 : (amount + currentIndex);
    trip->setCurrentPlaceIndex(newIndex);
}

void Traveller::setTravelMode(TravelMode *travelMode)
{
    if (this->travelMode != nullptr)
        delete this->travelMode;
    this->travelMode = travelMode;
}

Traveller::~Traveller()
{
    if (travelMode != nullptr)
        delete travelMode;
}

// getter and setters
int Traveller::getCoins()
{
    return coins;
}

void Traveller::setCoins(int coins)
{
    this->coins = coins;
}

int Traveller::getFlightItems()
{
    return flightItems;
}

void Traveller::setFlightItems(int flightItems)
{
    this->flightItems = flightItems;
}

TravelMode *Traveller::getTravelMode()
{
    return travelMode;
}