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
}

// getter and setters
Route *Trip::getRoute()
{
}

std::vector<Place *> Trip::getPlaces()
{
    return places;
}

void Trip::setPlaces(std::vector<Place *> places)
{
}

int Trip::getCurrentPlaceIndex()
{
}

void Trip::setCurrentPlaceIndex(int index)
{
}