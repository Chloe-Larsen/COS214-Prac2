#include "../../include/world_builder/DesertNPC.h"

DesertNPC::DesertNPC(std::string name) : NPC(name) {}

bool DesertNPC::sellsFlightItem()
{
    return false;
}