#pragma once

#include "Room.h"

class Apartment :public Room {
public:
	Apartment(unsigned number);
	double getPrice() const override;
	MyString getType() const override;
};

