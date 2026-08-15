#ifndef TREASURE_FEATURE_H
#define TREASURE_FEATURE_H

#include "PlaceFeature.h"
#include "../../world_builder/NPC.h"

class NpcFeature : public PlaceFeature
{
private:
    NPC *npc;

public:
    NpcFeature(Place* place, NPC *npc);
    // TODO: Map<String, Function(): void> getInteractions()
    std::vector<Obstacle *> getObstacles() override;
    ~NpcFeature();
};

#endif