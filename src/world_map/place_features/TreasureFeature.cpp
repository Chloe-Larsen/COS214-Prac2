#include "../../../include/world_map/place_features/TreasureFeature.h"

TreasureFeature::TreasureFeature(Place *place, int coins) : PlaceFeature(place)
{
    this->coins = coins;
}

void TreasureFeature::handleInteraction(Traveller *traveller)
{
    std::cout << "You found " << coins << " gold coins!" << std::endl;
    traveller->setCoins(traveller->getCoins() + coins);
    coins = 0;
}

std::map<std::string, PlaceFeature *> TreasureFeature::getInteractions()
{
    std::map<std::string, PlaceFeature *> map = place->getInteractions();
    if (coins > 0)
        map["Dig up treasure"] = this;
    return map;
}

std::vector<Obstacle *> TreasureFeature::getObstacles()
{
    return place->getObstacles();
}