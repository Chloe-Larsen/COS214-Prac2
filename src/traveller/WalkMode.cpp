#include "../../include/traveller/WalkMode.h"

WalkMode::WalkMode() : TravelMode("walking") {}

int WalkMode::handle(Terrain *terrain, Traveller *traveller)
{
    if (dynamic_cast<OceanTerrain *>(terrain))
    {
        std::cout << "You can try walk on water all you want. It's not gunna work." << std::endl;
        return 0;
    }

    std::cout << "You walked 1 space in the " << terrain->getName() << "!" << std::endl;
    return 1;
}