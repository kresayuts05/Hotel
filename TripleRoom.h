#pragma once

#include "Room.h"

class TripleRoom : public Room {
public:
    TripleRoom(unsigned number);

    unsigned getBeds() const override;
    MyString getType() const override;
};

