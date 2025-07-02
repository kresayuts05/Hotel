#pragma once

#include "Room.h"

class DoubleRoom :public Room {
public:
	DoubleRoom(unsigned number);

	unsigned getBeds() const override;
	MyString getType() const override;
};

