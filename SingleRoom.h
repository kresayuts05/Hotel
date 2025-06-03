#pragma once

#include "Room.h"

class SingleRoom : public Room {
public:
    SingleRoom(unsigned number);
    double getPrice() const override;
    MyString getType() const override;
};  