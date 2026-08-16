#include "../../include/world_builder/Terrain.h"

Terrain::Terrain(std::string name)
{
    this->name = name;
}

std::string Terrain::getName()
{
    return name;
}

Terrain::~Terrain()
{
    // empty
}