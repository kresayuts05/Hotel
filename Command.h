#pragma once

#include "MyString.h"

class Command
{
public:
    virtual void execute() = 0;
    virtual MyString getName() const = 0;
    virtual ~Command() {}
};

