#include "../../include/trip/Route.h"

Route::Route(std::string name)
{
    this->name = name;
}

std::string Route::getName()
{
    return name;
}

Route::~Route()
{
    // empty
}