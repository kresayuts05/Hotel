#include "Reservation.h"
#include <stdexcept>
#include <sstream>


//O� ����� ���������� � StackOverflow
Reservation::Reservation()
    : from(), to(), note(""), guests(1) {}

// ����� ����������� � ��������
Reservation::Reservation(const Date& from, const Date& to, const MyString& note, unsigned guests)
    : from(from), to(to), note(note), guests(guests) {
    if (to < from)
        throw std::invalid_argument("Error! End date before start date.");
    if (guests == 0)
        throw std::invalid_argument("Error! Guests should be atleast one.");
}

// ������
const Date& Reservation::getFrom() const { return from; }
const Date& Reservation::getTo() const { return to; }
const MyString& Reservation::getNote() const { return note; }
unsigned Reservation::getGuests() const { return guests; }

// ���� ������� ��������� ����
bool Reservation::includes(const Date& date) const {
    return !(date < from || date > to);
}

// ���� �� ���������� � ���� ������
bool Reservation::overlaps(const Date& otherFrom, const Date& otherTo) const {
    return !(to < otherFrom || from > otherTo);
}

// ����� ��� ������ ������������ � ����� ������
int Reservation::daysInPeriod(const Date& fromPeriod, const Date& toPeriod) const {
    Date start = (from > fromPeriod) ? from : fromPeriod;
    Date end = (to < toPeriod) ? to : toPeriod;

    if (start > end) {
        return 0;
    }

    return start.daysUntil(end); 
}

// ������������ ��� ����
void Reservation::serialize(std::ostream& os) const {
    os << from.toString().c_str() << ' '
        << to.toString().c_str() << ' '
        << guests << std::endl
        << note.c_str() << std::endl;
}

// ������ �� ����
Reservation Reservation::deserialize(std::istream& is) {
   /* MyString fromStr, toStr;
    unsigned guests;
    char buffer[1024];

    is >> fromStr >> toStr >> guests;
    is.ignore(); 
    is.getline(buffer, 1024);
    MyString note(buffer);

    Date from(fromStr);
    Date to(toStr);

    return Reservation(from, to, note, guests);*/

    std::string line;
    std::getline(is, line); // ����� � ������ � �������

    if (line.empty())
        throw std::runtime_error("������ ��� � ���� ��� ������ �� ����������");

    std::istringstream ss(line);
    std::string fromStr, toStr;
    unsigned guests;

    ss >> fromStr >> toStr >> guests;

    if (fromStr.empty() || toStr.empty())
        throw std::runtime_error("������ ���� ��� ��������� �� ����������");

    // �������������: �������� ����� ���� Date::parse(const char*)
    Date from = Date::parse(fromStr.c_str());
    Date to = Date::parse(toStr.c_str());

    // ������ �� ������� �� ������� ���
    std::string noteLine;
    std::getline(is, noteLine);

    MyString note(noteLine.c_str()); // ������������ ��� MyString

    return Reservation(from, to, note, guests);
}
