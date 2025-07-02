#pragma once
#include "Room.h"
#include "Vector.hpp"
#include "MyString.h"

class HotelClass {
private:
    Vector<Room*> rooms;
    MyString openedFile;

public:
    HotelClass() = default;
    ~HotelClass();

    void addRoom(Room* room);

    void checkIn(unsigned roomNumber, const Date& from, const Date& to, const MyString& note, unsigned guests = 0);
    void checkOut(unsigned roomNumber);

    void listAvailableRooms(const Date& date) const;
    void report(const Date& from, const Date& to) const;

    Room* findFreeRoom(unsigned minBeds, const Date& from, const Date& to) const;

    void saveToFile(const MyString& filename) const;
    void loadFromFile(const MyString& filename);
    void free();

    const MyString& getOpenedFileName() const;
    void setOpenedFileName(const MyString& name);
};