#include "DoubleRoom.h"

const unsigned capacity = 2;
const unsigned price = 70;

DoubleRoom::DoubleRoom(unsigned number) : Room(number, capacity) {}

double DoubleRoom::getPrice() const {
	return price;
}

MyString DoubleRoom::getType() const {
	return "Double";
}
