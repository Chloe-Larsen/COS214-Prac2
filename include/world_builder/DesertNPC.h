#ifndef DESERT_NPC_H
#define DESERT_NPC_H

#include "NPC.h"

class DesertNPC : public NPC
{
public:
    DesertNPC(std::string name);
    bool sellsFlightItem();
};

#endif