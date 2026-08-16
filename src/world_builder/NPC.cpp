#include "../../include/world_builder/NPC.h"

NPC::NPC(std::string name)
{
    this->name = name;
}

NPC::~NPC()
{
}

std::string NPC::getName()
{
    return name;
}