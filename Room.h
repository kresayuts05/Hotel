#pragma once
class Room
{
public:
	unsigned getNumber() const;
	unsigned getCapacity() const;

private:
	unsigned number;
	unsigned capacity;
	bool has�errace = false;
	bool hasBath = false;
	bool isPremium = false;
};

