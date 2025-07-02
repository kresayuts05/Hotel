#pragma once

#include "Room.h"

class Apartment :public Room {
public:
	Apartment(unsigned number);

	unsigned getBeds() const override;
	MyString getType() const override;
};

