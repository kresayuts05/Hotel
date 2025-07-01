#include "CheckInCommand.h"
#include <stdexcept>

CheckInCommand::CheckInCommand(unsigned roomNumber,
    const Date& from,
    const Date& to,
    const MyString& note,
    int guests)
    : roomNumber(roomNumber), from(from), to(to), note(note), guests(guests)
{
    if (to < from)
        throw std::invalid_argument("Крайна дата е преди началната.");
}

void CheckInCommand::execute(Hotel& hotel) {
    bool success = hotel.checkIn(roomNumber, from, to, note, guests);
    if (!success)
        throw std::runtime_error("Неуспешен check-in – стаята може вече да е заета.");
}