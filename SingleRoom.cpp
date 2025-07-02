#include "SingleRoom.h"

const unsigned capacity = 1;

SingleRoom::SingleRoom(unsigned number) : Room(number, capacity) {}

unsigned SingleRoom::getBeds() const { 
	return capacity; 
}

MyString SingleRoom::getType() const { 
	return "single"; 
}
