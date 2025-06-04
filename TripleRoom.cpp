#include "TripleRoom.h"

const unsigned capacity = 3;
const unsigned price = 100;

TripleRoom::TripleRoom(unsigned number) : Room(number, capacity) {}

double TripleRoom::getPrice() const {
	return price;
}

MyString TripleRoom::getType() const {
	return "Triple";
}