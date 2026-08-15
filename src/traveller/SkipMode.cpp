#include "../../include/traveller/SkipMode.h"

int SkipMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (OceanTerrain *c = dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "You cannot skip in the ocean terrain. Please select a different travel mode." << std::endl;
        return 0;
    }
    std::string terrainString = "desert";
    if (CityTerrain *c = dynamic_cast<CityTerrain *>(terrain))
    {
        terrainString = "city";
    }

    std::cout << "You have skipped 1 space in the " << terrainString << " terrain!" << std::endl;
    return 1;
}