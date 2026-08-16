#ifndef OCEAN_NPC_H
#define OCEAN_NPC_H

#include "NPC.h"

class OceanNPC : public NPC
{
public:
    OceanNPC(std::string name);
    bool sellsFlightItem();
};

#endif