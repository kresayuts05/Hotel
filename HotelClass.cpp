#include "HotelClass.h"

#include <iostream>
#include <stdexcept>

Hotel::Hotel() {}

Hotel::~Hotel() {
    clear();
}

void Hotel::clear() {
    for (size_t i = 0; i < rooms.getSize(); ++i)
        delete rooms[i];
    rooms.clear();
}

void Hotel::addRoom(Room* room) {
    if (!room)
        throw std::invalid_argument("���� �� �������� �� ������ ����.");
    rooms.push_back(room);
}

Room* Hotel::findRoom(unsigned roomNumber) const {
    for (size_t i = 0; i < rooms.getSize(); ++i)
        if (rooms[i]->getNumber() == roomNumber)
            return rooms[i];
    return nullptr;
}

bool Hotel::checkIn(unsigned roomNumber, const Date& from, const Date& to, const MyString& note, int guests) {
    Room* room = findRoom(roomNumber);
    if (!room)
        throw std::invalid_argument("���� ������ ����.");

    if (room->getIsOccupied())
        return false;

    room->occupy(); // set isOccupied = true
    // �� �����: ����� �� ������� ������� ����� ��� (�� � ������������, ��� �� �� ������)
    return true;
}

bool Hotel::checkOut(unsigned roomNumber) {
    Room* room = findRoom(roomNumber);
    if (!room)
        throw std::invalid_argument("������ �� ����������.");

    if (!room->getIsOccupied())
        return false;

    room->vacate(); // set isOccupied = false
    return true;
}

void Hotel::listAvailableRooms(const Date& onDate) const {
    std::cout << "�������� ���� �� " << onDate.toString() << ":\n";
    for (size_t i = 0; i < rooms.getSize(); ++i) {
        if (!rooms[i]->getIsOccupied()) {
            std::cout << " - ���� " << rooms[i]->getNumber() << " (" << rooms[i]->getType() << ")\n";
        }
    }
}

void Hotel::reportOccupiedRooms(const Date& from, const Date& to) const {
    std::cout << "����� ���� �� " << from.toString() << " �� " << to.toString() << ":\n";
    for (size_t i = 0; i < rooms.getSize(); ++i) {
        if (rooms[i]->getIsOccupied()) {
            std::cout << " - ���� " << rooms[i]->getNumber() << " (" << rooms[i]->getType() << ")\n";
        }
    }
}