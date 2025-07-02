#pragma once
#include "MyString.h"
#include "Date.h"
#include <iostream>

class Reservation {
private:
    Date from;
    Date to;
    MyString note;
    unsigned guests;

public:
    Reservation();
    Reservation(const Date& from, const Date& to, const MyString& note, unsigned guests);

    const Date& getFrom() const;
    const Date& getTo() const;
    const MyString& getNote() const;
    unsigned getGuests() const;

    bool includes(const Date& date) const;
    bool overlaps(const Date& otherFrom, const Date& otherTo) const;

    int daysInPeriod(const Date& periodFrom, const Date& periodTo) const;

    void serialize(std::ostream& os) const;
    static Reservation deserialize(std::istream& is);
};