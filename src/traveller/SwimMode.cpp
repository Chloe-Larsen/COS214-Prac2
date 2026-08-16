#include "../../include/traveller/SwimMode.h"

SwimMode::SwimMode() : TravelMode("swimming") {}

int SwimMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "You have swam 1 space in the ocean terrain!" << std::endl;
        return 1;
    }
    std::string terrainString = "desert";
    if (dynamic_cast<CityTerrain *>(terrain))
    {
        terrainString = "city";
    }

    std::cout << "You cannot swim in the " << terrainString << " terrain. Please select a different travel mode" << std::endl;
    return 0;
}