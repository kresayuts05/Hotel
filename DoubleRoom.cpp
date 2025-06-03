#include "DoubleRoom.h"

const unsigned capacity = 2;

DoubleRoom::DoubleRoom(unsigned number) : Room(number, capacity) {}

double DoubleRoom::getPrice() const {
	return 70.0;
}

MyString DoubleRoom::getType() const {
	return "Double";
}
