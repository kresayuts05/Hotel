#include "Apartment.h"

const unsigned capacity = 4;

Apartment::Apartment(unsigned number) : Room(number, capacity) {}

double Apartment::getPrice() const {
	return 120.0;
}

MyString Apartment::getType() const {
	return "Apartment";
}
