#pragma once
#include "Room.h"
#include "Vector.hpp"
#include "MyString.h"
#include "Date.h"

class Hotel {
public:
    Hotel();
    ~Hotel();

    void addRoom(Room* room);
    Room* findRoom(unsigned roomNumber) const;

    bool checkIn(unsigned roomNumber, const Date& from, const Date& to, const MyString& note, int guests = -1);
    bool checkOut(unsigned roomNumber);

    void listAvailableRooms(const Date& onDate) const;
    void reportOccupiedRooms(const Date& from, const Date& to) const;

    void clear();

private:
    Vector<Room*> rooms;
};

