#include "../../include/traveller/WalkMode.h"

WalkMode::WalkMode() : TravelMode("walking") {}

int WalkMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "You cannot walk in the ocean terrain. Please select a different mode." << std::endl;
        return 0;
    }
    std::string terrainString = "desert";
    if (dynamic_cast<CityTerrain *>(terrain))
    {
        terrainString = "city";
    }

    std::cout << "You have walk 1 space in the " << terrainString << " terrain!" << std::endl;
    return 1;
}