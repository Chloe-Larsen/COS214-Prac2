#include "../../include/traveller/SkipMode.h"

SkipMode::SkipMode() : TravelMode("skipping") {}

int SkipMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "Are you trying to skip on water? You can't even walk on water. Try something else, don't overthink it... Maybe something like swimming." << std::endl;
        return 0;
    }

    std::cout << "Feeling happy? You skipped 1 space in the " << terrain->getName() << "!" << std::endl;
    return 1;
}