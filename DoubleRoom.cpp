#include "DoubleRoom.h"

const unsigned capacity = 2;

DoubleRoom::DoubleRoom(unsigned number) : Room(number, capacity) {}

unsigned DoubleRoom::getBeds() const {
	return capacity;
}

MyString DoubleRoom::getType() const {
	return "double";
}
