#include "../../include/world_builder/CityNPC.h"

CityNPC::CityNPC(std::string name) : NPC(name) {}

bool CityNPC::sellsFlightItem()
{
    return false;
}