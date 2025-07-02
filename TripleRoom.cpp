#include "TripleRoom.h"

const unsigned capacity = 3;

TripleRoom::TripleRoom(unsigned number) : Room(number, capacity) {}

unsigned TripleRoom::getBeds() const {
	return capacity;
}

MyString TripleRoom::getType() const {
	return "triple";
}