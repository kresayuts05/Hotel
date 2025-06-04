#include "Apartment.h"

const unsigned capacity = 4;
const unsigned price = 120;

Apartment::Apartment(unsigned number) : Room(number, capacity) {}

double Apartment::getPrice() const {
	return price;
}

MyString Apartment::getType() const {
	return "Apartment";
}
