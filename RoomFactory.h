#pragma once

#include "MyString.h"
#include "Room.h"

/// �������� ���� �� ��������� �� Room* �� ��� �� ���
class RoomFactory {
public:
	/// ������� ���� �� ������� ��� � �����
	static Room* create(const MyString& roomTypeName, int roomNumber);
};


