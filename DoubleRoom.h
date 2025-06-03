#pragma once

#include "Room.h"

class DoubleRoom :public Room {
public:
	DoubleRoom(unsigned number);
	double getPrice() const override;
	MyString getType() const override;
};

