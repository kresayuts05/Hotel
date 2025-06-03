#include "Room.h"

Room::Room(unsigned number, unsigned capacity) : number(number), capacity(capacity), isOccupied(false) {}

unsigned Room::getNumber() const {
	return number;
}

unsigned Room::getCapacity() const
{
	return capacity;
}

bool Room::getIsOccupied() const {
	return isOccupied;
}

void Room::occupy() {
	isOccupied = true;
}

void Room::vacate() {
	isOccupied = false;
}