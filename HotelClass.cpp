#include "HotelClass.h"
#include "RoomFactory.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

HotelClass::~HotelClass() {
	free();
}

void HotelClass::free() {
	for (size_t i = 0; i < rooms.getSize(); ++i) {
		delete rooms[i];
	}

	rooms.clear();
}

//Добавя създадена стая в списъка със стаи в хотела
void HotelClass::addRoom(Room* room) {
	for (size_t i = 0; i < rooms.getSize(); ++i) {
		if (rooms[i]->getNumber() == room->getNumber()) {
			throw std::logic_error("Room with this number already exists.");
		}
	}

	rooms.push_back(room);
}

//Настанява гости в дадена стая и сменя статуса и на заета
void HotelClass::checkIn(unsigned roomNumber, const Date& from, const Date& to, const MyString& note, unsigned guests) {
	for (size_t i = 0; i < rooms.getSize(); i++) {
		if (rooms[i]->getNumber() == roomNumber) {
			unsigned count = (guests == 0) ? rooms[i]->getBeds() : guests;
			Reservation res(from, to, note, count);
			rooms[i]->checkIn(res);
			return;
		}
	}
	throw std::logic_error("Стая с този номер не съществува.");
}

//освобождава стаята
void HotelClass::checkOut(unsigned roomNumber) {
	for (size_t i = 0; i < rooms.getSize(); i++) {
		if (rooms[i]->getNumber() == roomNumber) {
			rooms[i]->checkOut();
			return;
		}
	}
	throw std::logic_error("A room with this number doesn not exist.");
}

//принтира списък със всички свободни стаи в хотела
void HotelClass::listAvailableRooms(const Date& date) const {
	bool found = false;
	for (size_t i = 0; i < rooms.getSize(); i++) {
		if (rooms[i]->isAvailableOn(date)) {
			std::cout << "Room " << rooms[i]->getNumber() << " (" << rooms[i]->getType() << ", beds: " << rooms[i]->getBeds() << ")" << std::endl;
			found = true;
		}
	}
	if (!found) {
		std::cout << "No rooms available on " << date.toString() << std::endl;
	}
}

//принтира репорт за заетостта на всички стаи в даден период от време
void HotelClass::report(const Date& from, const Date& to) const {
	for (size_t i = 0; i < rooms.getSize(); i++) {
		int used = rooms[i]->daysUsedBetween(from, to);
		if (used > 0)
			std::cout << "Room " << rooms[i]->getNumber() << " is occupied for  " << used << " days" << std::endl;
	}
}

//Намира свободна стая 
Room* HotelClass::findFreeRoom(unsigned minBeds, const Date& from, const Date& to) const {
	Room* best = nullptr;

	for (size_t i = 0; i < rooms.getSize(); i++) {
		if (rooms[i]->getBeds() >= minBeds && rooms[i]->isAvailableInPeriod(from, to)) {
			if (!best || rooms[i]->getBeds() < best->getBeds())
				best = rooms[i];
		}
	}

	return best;
}

//Пише информацията за всички стаи във файл
void HotelClass::saveToFile(const MyString& filename) const {
	std::ofstream ofs(filename.c_str());
	if (!ofs) {
		throw std::runtime_error("Error. Could not write in the file.");
	}

	ofs << rooms.getSize() << std::endl;
	for (size_t i = 0; i < rooms.getSize(); ++i) {
		rooms[i]->serialize(ofs);
	}

	std::cout << "All data written in file: " << filename << std::endl;
}

//Зарежда стаи от фаил
void HotelClass::loadFromFile(const MyString& filename) {
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open()) {
		throw std::runtime_error("Fail could not open.");
	}

	free();

	size_t count;
	ifs >> count;	
	ifs.ignore();

	for (size_t i = 0; i < count; ++i) {
		/*MyString type;
		unsigned number;
		ifs >> type >> number;
		ifs.ignore();*/
		std::string line;
		std::getline(ifs, line);

		// разделяме ръчно реда
		std::istringstream ss(line);
		std::string rawType;
		unsigned number;

		ss >> rawType >> number;

		while (!rawType.empty() && (rawType.back() == '\r' || rawType.back() == '\n' || rawType.back() == ' ')) {
			rawType.pop_back();
		}

		// създаваме MyString
		MyString type(rawType.c_str());

		Room* room = RoomFactory::create(type, number);
		room->deserialize(ifs);
		addRoom(room);
	}

	openedFile = filename;
	std::cout << "Successfully loaded " << count << " rooms from " << filename << std::endl;
}

//взима името на отворен файл
const MyString& HotelClass::getOpenedFileName() const {
	return openedFile;
}

//задава име на файл
void HotelClass::setOpenedFileName(const MyString& name) {
	openedFile = name;
}