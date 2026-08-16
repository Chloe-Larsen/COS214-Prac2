#include "../../include/traveller/SwimMode.h"

SwimMode::SwimMode() : TravelMode("swimming") {}

int SwimMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "You swam 1 space!" << std::endl;
        return 1;
    }
    if (dynamic_cast<DesertTerrain *>(terrain))
    {
        std::cout << "You really just swam through sand instead of walking over it? Whatever floats your boat I guess." << std::endl;
        return 1;
    }

    std::cout << "There ain't any pools in this city, so unfortunately for you, you can't swim here. Try something else." << std::endl;
    return 0;
}