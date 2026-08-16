#include "../../include/trip/Trip.h"

void Trip::plan(Location *current, Location *destination)
{
    places = route->pickPlaces(current, destination);
}

void Trip::setRoute(Route *route)
{
    if (this->route != nullptr)
        delete this->route;
    this->route = route;
}

Trip::~Trip()
{
    if(route != nullptr)
        delete route;

    for (Place *place : places)
    {
        delete place;
    }
}

// getter and setters
Route *Trip::getRoute()
{
    return route;
}

std::vector<Place *> Trip::getPlaces()
{
    return places;
}

int Trip::getCurrentPlaceIndex()
{
    return currentPlacesIndex;
}

void Trip::setCurrentPlaceIndex(int index)
{
    this->currentPlacesIndex = index;
}