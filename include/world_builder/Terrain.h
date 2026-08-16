#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

class Terrain
{
private:
    std::string name;

public:
    Terrain(std::string name);
    virtual std::string getName() final;
    virtual ~Terrain();
};

#endif