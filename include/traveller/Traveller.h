#ifndef TRAVELLER_H
#define TRAVELLER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "TravelMode.h"
#include "../trip/Trip.h"
#include "../world_map/Place.h"

class Traveller
{
private:
    int coins;
    int flightItems;
    TravelMode *travelMode;

public:
    void move(Trip *trip, Terrain *terrain);
    void setTravelMode(TravelMode * travelMode);
    ~Traveller();

    //getter and setters
    int getCoins();
    void setCoins(int coins);

    int getFlightItems();
    void setFlightItems(int flightItems);

    TravelMode* getTravelMode();
};

#endif