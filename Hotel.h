#pragma once
#include "Room.h"
#include "Vector.hpp"

class Hotel {
public:
    Hotel(std::string name);
    //virtual?????
    ~Hotel();

    void loadRoomsFromFile(const std::string& filename);
    void showAvailableRooms() const;

private:
    std::string name;
    Vector<Room*> rooms;
};

