#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>

class Obstacle
{
private:
    std::string name;

public:
    Obstacle(std::string name);
    virtual std::string getName() final;
    virtual ~Obstacle();
};

#endif