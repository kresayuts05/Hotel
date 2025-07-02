#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Reservation.h"
#include "Date.h"

class Room {
private:
    unsigned number;
    unsigned beds;
    Vector<Reservation> reservations;

public:
    Room(unsigned number, unsigned beds);

    unsigned getNumber() const;
    virtual unsigned getBeds() const = 0;
    virtual MyString getType() const = 0;
        
    bool isAvailableOn(const Date& date) const;
    bool isAvailableInPeriod(const Date& from, const Date& to) const;

    void checkIn(const Reservation& res);
    void checkOut(); // маха последната резервация

    int daysUsedBetween(const Date& from, const Date& to) const;

    void printInfo() const;

    virtual void serialize(std::ostream& os) const;
    virtual void deserialize(std::istream& is);
};