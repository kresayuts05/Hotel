#include "SingleRoom.h"

const unsigned capacity = 2;

SingleRoom::SingleRoom(unsigned number) : Room(number, capacity) {}

double SingleRoom::getPrice() const {
	return 50.0;
}

MyString SingleRoom::getType() const {
	return "Single";
}
