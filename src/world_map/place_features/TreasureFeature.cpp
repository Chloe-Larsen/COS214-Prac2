#include "../../../include/world_map/place_features/TreasureFeature.h"

TreasureFeature::TreasureFeature(int coins, Place *place) : PlaceFeature(place)
{
    this->coins = coins;
}

void TreasureFeature::handleInteraction(Traveller *traveller)
{
    int amount = 0.7 * coins;

    if (amount < 10)
        amount = 10;
    if (amount > coins)
        amount = coins;

    std::cout << "You found " << amount << " gold coins!" << std::endl;
    traveller->setCoins(traveller->getCoins() + amount);
    coins -= amount;
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