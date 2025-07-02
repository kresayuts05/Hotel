#include "HotelClass.h"
#include "Date.h"
#include "Reservation.h"
#include <iostream>
#include <stdexcept>

#include "Vector.hpp"
#include "MyString.h"
#include "Command.h"
#include "HotelCommands.h"

using namespace HotelCommands;

void CheckinCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	if (args.getSize() < 5) {
		throw std::invalid_argument("Not in the coreect format. Format: checkin <room> <from> <to> <note> [<guests>]");
	}

	unsigned room = args[1].toUInt();
	Date from(args[2]);
	Date to(args[3]);
	MyString note = args[4];
	unsigned guests = (args.getSize() > 5) ? args[5].toUInt() : 0;

	hotel.checkIn(room, from, to, note, guests);
	std::cout << "Succesfully checked in." << std::endl;
}

void AvailabilityCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	Date date = (args.getSize() >= 2) ? Date(args[1]) : Date(); // днешна по подразбиране
	hotel.listAvailableRooms(date);
}

void CheckoutCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	if (args.getSize() < 2) {
		throw std::invalid_argument("Incorect format. Format: checkout <room>");
	}

	unsigned room = args[1].toUInt();
	hotel.checkOut(room);
	std::cout << "Room checked out.\n";
}

void ReportCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	if (args.getSize() < 3) {
		throw std::invalid_argument("Incorrect format. Format: report <from> <to>");
	}

	Date from(args[1]);
	Date to(args[2]);
	hotel.report(from, to);
}

void FindCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	if (args.getSize() < 4) {
		throw std::invalid_argument("Incorrect format. Format: find <beds> <from> <to>");
	}

	unsigned beds = args[1].toUInt();
	Date from(args[2]);
	Date to(args[3]);

	Room* room = hotel.findFreeRoom(beds, from, to);
	if (!room) {
		std::cout << "No available room in this time period." << std::endl;
	}
	else {
		std::cout << "Offer: room " << room->getNumber() << " (" << room->getBeds() << " beds)" << std::endl;
	}
}

//Обявява стаята за недостъпна заради ремонт
void UnavailableCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
	if (args.getSize() < 5) {
		throw std::invalid_argument("Format: unavailable <room> <from> <to> <note>");
	}

	unsigned room = args[1].toUInt();
	Date from(args[2]);
	Date to(args[3]);

	// note
	MyString note = args[4];
	for (size_t i = 5; i < args.getSize(); ++i) {
		note = note + " " + args[i];
	}

	hotel.checkIn(room, from, to, note, 0);

	std::cout << "Room " << room << " is unavailable from "
		<< from.toString().c_str() << " to " << to.toString().c_str()
		<< " because: " << note.c_str() << std::endl;
}
