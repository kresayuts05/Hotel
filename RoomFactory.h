#pragma once

#include "MyString.h"
#include "Room.h"

/// Фабричен клас за създаване на Room* по име на тип
class RoomFactory {
public:
	/// Създава стая от дадения тип и номер
	static Room* create(const MyString& roomTypeName, int roomNumber);
};


