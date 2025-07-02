#include "Apartment.h"

const unsigned capacity = 4;

Apartment::Apartment(unsigned number) : Room(number, capacity) {}

unsigned Apartment::getBeds() const {
	return capacity;
}

MyString Apartment::getType() const {
	return "àpartment";
}
