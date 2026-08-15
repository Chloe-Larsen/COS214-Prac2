#ifndef NPC_H
#define NPC_H

class NPC
{
private:
    std::string name;
    bool sellsFlightItem;
public: 
    virtual ~NPC();
};

#endif