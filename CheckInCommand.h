#pragma once

#include "MyString.h"
#include "Date.h"
#include "Command.h"
#include "HotelClass.h"

class CheckInCommand : public Command {
private:
    unsigned roomNumber;
    Date from;
    Date to;
    MyString note;
    int guests;

public:
    CheckInCommand(unsigned roomNumber,
        const Date& from,
        const Date& to,
        const MyString& note,
        int guests = -1);

    void execute(Hotel& hotel) override;
};

