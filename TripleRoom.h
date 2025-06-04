#pragma once

#include "Room.h"

class TripleRoom : public Room {
public:
    TripleRoom(unsigned number);
    double getPrice() const override;
    MyString getType() const override;
};

