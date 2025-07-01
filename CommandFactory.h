#pragma once
#include "Command.h"
#include "MyString.h"
#include "Vector.hpp"

class CommandFactory {
public:
    static Command* create(const MyString& commandName, const Vector<MyString>& args);
};

