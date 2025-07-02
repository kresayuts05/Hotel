#include "Reservation.h"
#include <stdexcept>
#include <sstream>


//Oт части съобразено с StackOverflow
Reservation::Reservation()
    : from(), to(), note(""), guests(1) {}

// Пълен конструктор с проверки
Reservation::Reservation(const Date& from, const Date& to, const MyString& note, unsigned guests)
    : from(from), to(to), note(note), guests(guests) {
    if (to < from)
        throw std::invalid_argument("Error! End date before start date.");
    if (guests == 0)
        throw std::invalid_argument("Error! Guests should be atleast one.");
}

// Гетъри
const Date& Reservation::getFrom() const { return from; }
const Date& Reservation::getTo() const { return to; }
const MyString& Reservation::getNote() const { return note; }
unsigned Reservation::getGuests() const { return guests; }

// Дали включва конкретна дата
bool Reservation::includes(const Date& date) const {
    return !(date < from || date > to);
}

// Дали се припокрива с друг период
bool Reservation::overlaps(const Date& otherFrom, const Date& otherTo) const {
    return !(to < otherFrom || from > otherTo);
}

// Колко дни попада резервацията в даден период
int Reservation::daysInPeriod(const Date& fromPeriod, const Date& toPeriod) const {
    Date start = (from > fromPeriod) ? from : fromPeriod;
    Date end = (to < toPeriod) ? to : toPeriod;

    if (start > end) {
        return 0;
    }

    return start.daysUntil(end); 
}

// Сериализация във файл
void Reservation::serialize(std::ostream& os) const {
    os << from.toString().c_str() << ' '
        << to.toString().c_str() << ' '
        << guests << std::endl
        << note.c_str() << std::endl;
}

// Четене от файл
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
    std::getline(is, line); // редът с датите и гостите

    if (line.empty())
        throw std::runtime_error("Липсва ред с дати при четене на резервация");

    std::istringstream ss(line);
    std::string fromStr, toStr;
    unsigned guests;

    ss >> fromStr >> toStr >> guests;

    if (fromStr.empty() || toStr.empty())
        throw std::runtime_error("Липсва дата при прочитане на резервация");

    // Преобразуване: очакваме метод като Date::parse(const char*)
    Date from = Date::parse(fromStr.c_str());
    Date to = Date::parse(toStr.c_str());

    // Четене на бележка на отделен ред
    std::string noteLine;
    std::getline(is, noteLine);

    MyString note(noteLine.c_str()); // конвертираме към MyString

    return Reservation(from, to, note, guests);
}
