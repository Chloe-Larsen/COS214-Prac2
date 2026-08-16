#ifndef NPC_H
#define NPC_H

#include <string>

class NPC
{
private:
    std::string name;
    bool sellsFlightItem;

public:
    virtual ~NPC();
};

#endif