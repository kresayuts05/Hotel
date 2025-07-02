#pragma once

#include "Room.h"

class SingleRoom : public Room {
public:
    SingleRoom(unsigned number);

    MyString getType() const override;
    unsigned getBeds() const override;
};  