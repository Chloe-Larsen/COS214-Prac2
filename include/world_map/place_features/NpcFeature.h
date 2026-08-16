#ifndef NPC_FEATURE_H
#define NPC_FEATURE_H

#include "PlaceFeature.h"
#include "../../world_builder/NPC.h"

class NpcFeature : public PlaceFeature
{
private:
    NPC *npc;

public:
    NpcFeature(NPC *npc, Place *place);
    void handleInteraction(Traveller *traveller) override;
    std::map<std::string, PlaceFeature *> getInteractions() override;
    std::vector<Obstacle *> getObstacles() override;
    ~NpcFeature();
};

#endif