#include "../../include/traveller/FlyMode.h"
#include "../../include/traveller/Traveller.h"

FlyMode::FlyMode() : TravelMode("flying") {}

int FlyMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (traveller->getFlightItems() <= 0)
    {
        std::cout << "You don't have any feathers! You need feathers to fly... Try talking to an NPC to get some." << std::endl;
        return 0;
    }

    traveller->setFlightItems(traveller->getFlightItems() - 1);
    std::cout << "You flew 3 spaces in the " << terrain->getName() << "! \nYou have " << std::to_string(traveller->getFlightItems()) << " feathers left." << std::endl;
    return 3;
}