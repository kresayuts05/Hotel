#pragma once

#include "HotelClass.h"

class Command
{
public:
    virtual ~Command() {};
    virtual void execute(const Vector<MyString>& args, HotelClass& hotel) = 0;
};

