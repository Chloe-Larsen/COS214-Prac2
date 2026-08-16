#ifndef CITY_NPC_H
#define CITY_NPC_H

#include "NPC.h"

class CityNPC : public NPC
{
public:
    CityNPC(std::string name);
    bool sellsFlightItem();
};

#endif