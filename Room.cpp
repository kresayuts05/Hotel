#include "Room.h"
#include <stdexcept>
#include <iostream>


Room::Room(unsigned number, unsigned beds) : number(number), beds(beds) {
	if (beds == 0) {
		throw std::invalid_argument("Room cannot be with 0 beds.");
	}
}

unsigned Room::getNumber() const {
	return number;
}

unsigned Room::getBeds() const {
	return beds;
}

//Проверява заетостта на дадена дата
bool Room::isAvailableOn(const Date& date) const {
	for (size_t i = 0; i < reservations.getSize(); i++) {
		if (reservations[i].includes(date)) {
			return false;
		}
	}

	return true;
}

//Проверява заетостта между дати
bool Room::isAvailableInPeriod(const Date& from, const Date& to) const {
	for (size_t i = 0; i < reservations.getSize(); i++) {
		if (reservations[i].overlaps(from, to)) {
			return false;
		}
	}

	return true;
}

//Прави резервация
void Room::checkIn(const Reservation& res) {
	if (!isAvailableInPeriod(res.getFrom(), res.getTo())) {
		throw std::logic_error("Room is not available then.");
	}

	reservations.push_back(res);
}

//Маxa последната резервация 
void Room::checkOut() {
	if (reservations.getSize() == 0) {
		throw std::logic_error("No active reservations for that room.");
	}

	reservations.pop_back();
}

//Колко дни от резервацията попадат в периода от време. Помощна функция за report
int Room::daysUsedBetween(const Date& from, const Date& to) const {
	int total = 0;
	for (size_t i = 0; i < reservations.getSize(); i++) {
		total += reservations[i].daysInPeriod(from, to);
	}

	return total;
}

//Сериализира информацията за резервациите на стая
void Room::serialize(std::ostream& os) const {
	os << getType() << ' ' << getNumber() << std::endl;
	os << reservations.getSize() << std::endl;

	for (size_t i = 0; i < reservations.getSize(); ++i) {
		reservations[i].serialize(os);
	}
}

//Десериализира информацията за резервациите на стая
void Room::deserialize(std::istream& is) {
	size_t count;
	is >> count;
	is.ignore();
	reservations.clear();

	for (size_t i = 0; i < count; ++i) {
		reservations.push_back(Reservation::deserialize(is));
	}
}

//принтира цялата информация за стаята
void Room::printInfo() const {
	std::cout << "Room №" << getNumber() << " (" << getType() << "), Reservations: " << reservations.getSize() << std::endl;
}