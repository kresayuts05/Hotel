#pragma once
#include "MyString.h"

class Room
{
public:
	Room(unsigned number, unsigned capacity);
	virtual ~Room() = default;

	unsigned getNumber() const;
	unsigned getCapacity() const;
	bool getIsOccupied() const;

	void occupy();
	void vacate();

	virtual double getPrice() const = 0;
	virtual MyString getType() const = 0;

protected:
	unsigned number;
	bool isOccupied;
	unsigned capacity;
	//TODO:
	bool has“errace = false;
	bool hasBath = false;
	bool isPremium = false;
};

