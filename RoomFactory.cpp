#include "RoomFactory.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "TripleRoom.h"
#include "Apartment.h"
#include <stdexcept>

Room* RoomFactory::create(const MyString& roomTypeName, int roomNumber) {

	if (roomTypeName == "single") {
		return new SingleRoom(roomNumber);
	}
	else if (roomTypeName == "double") {
		return new DoubleRoom(roomNumber);
	}
	else if (roomTypeName == "triple") {
		return new TripleRoom(roomNumber);
	}
	else if (roomTypeName == "apartment") {
		return new Apartment(roomNumber);
	}

	throw std::invalid_argument(
		std::string("Unknown room type: ") + roomTypeName.c_str()
	);
}