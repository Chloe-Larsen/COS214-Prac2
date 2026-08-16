#ifndef NPC_H
#define NPC_H

#include <string>

class NPC
{
private:
    std::string name;

public:
    NPC(std::string name);
    virtual std::string getName() final;
    virtual bool sellsFlightItem() = 0;
    virtual ~NPC();
};

#endif