#include "../../include/traveller/FlyMode.h"

int FlyMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (traveller->getFlightItems() <= 0)
    {
        std::cout << "You do not have any flight items. Please select a different travel mode." << std::endl;
        return 0;
    }

    std::string terrainString = "ocean";    
    if (CityTerrain *c = dynamic_cast<CityTerrain *>(terrain))
    {        
        terrainString = "city";
    }
    else if(DesertTerrain *c = dynamic_cast<DesertTerrain *>(terrain)){
        terrainString = "desert";
    }

    std::cout << "You have flown 3 spaces in the " << terrainString <<" terrain! \nYou have " << std::to_string(traveller->getFlightItems()) << " flight items remaining" << std::endl;
    return 3;
}