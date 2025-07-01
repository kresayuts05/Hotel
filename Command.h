#pragma once

#include "HotelClass.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(Hotel& hotel) = 0;
};

