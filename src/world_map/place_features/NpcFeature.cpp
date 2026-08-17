#include "../../../include/world_map/place_features/NpcFeature.h"
#include "../../../include/utils.h"

NpcFeature::NpcFeature(NPC *npc, Place *place) : PlaceFeature(place)
{
    this->npc = npc;
}

void NpcFeature::handleInteraction(Traveller *traveller)
{
    if (npc->sellsFlightItem())
    {
        int optionI = showMenu({npc->getName() + ": Hello there. Would you be interested in purchasing some feathers?"}, {"Yes please!", "How much are they?", "Absolutely not."});

        switch (optionI)
        {
        case 1:
        {
            if (traveller->getCoins() < 100)
            {
                std::cout << npc->getName() << ": You fool. You don't have enough gold coins..." << std::endl;
            }
            else
            {
                traveller->setFlightItems(traveller->getFlightItems() + 1);
                traveller->setCoins(traveller->getCoins() - 100);
                std::cout << npc->getName() << ": Alright here's a feather. Pleasure doing business." << std::endl;
            }

            break;
        }
        case 2:
        {
            std::cout << npc->getName() << ": It's 100 gold coins for one. Sounds expensive, but they are incredibly rare!" << std::endl;
            break;
        }
        case 3:
        {
            std::cout << npc->getName() << ": Fine, then quit wasting my time." << std::endl;
            break;
        }
        }
    }
    else
    {
        int optionI = showMenu({npc->getName() + ": Hi! What's up?"}, {"The sky.", "Not much, you?", "Do you have any feathers?", "I'm leaving now."});

        switch (optionI)
        {
        case 1:
        {
            std::cout << npc->getName() << ": I guess you're not wrong." << std::endl;
            break;
        }
        case 2:
        {
            std::cout << npc->getName() << ": Not much either, just chilling here in the " << place->getTerrain()->getName() << "." << std::endl;
            break;
        }
        case 3:
        {
            optionI = showMenu({npc->getName() + ": Feathers? Nah, but I've heard they let you fly."}, {"Really?", "I already know that stupid.", "That's so cool!"});

            switch (optionI)
            {
            case 1:
            {
                std::cout << npc->getName() << ": Yeah! I'm sure there are people in other places who might be willing to sell you some." << std::endl;
                break;
            }
            case 2:
            {
                std::cout << npc->getName() << ": Whoa. You're not gunna make any friends talking like that." << std::endl;
                break;
            }
            case 3:
            {
                std::cout << npc->getName() << ": I know right, wish I had some..." << std::endl;
                break;
            }
            }

            break;
        }
        case 4:
        {
            std::cout << npc->getName() + ": Okay, buddy." << std::endl;
            break;
        }
        }
    }
}

std::map<std::string, PlaceFeature *> NpcFeature::getInteractions()
{
    std::map<std::string, PlaceFeature *> map = place->getInteractions();
    map["Talk to " + npc->getName()] = this;
    return map;
}

std::vector<Obstacle *> NpcFeature::getObstacles()
{
    return place->getObstacles();
}

NpcFeature::~NpcFeature()
{
    delete npc;
}

std::string NpcFeature::toString()
{
    return "NpcFeature(npc: " + npc->getName() + ", place: " + place->toString() + ")";
}