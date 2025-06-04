#include "SingleRoom.h"

const unsigned capacity = 2;
const unsigned price = 50;

SingleRoom::SingleRoom(unsigned number) : Room(number, capacity) {}

double SingleRoom::getPrice() const {
	return price;
}

MyString SingleRoom::getType() const {
	return "Single";
}
