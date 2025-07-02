#pragma once

#include "Command.h"
#include "HotelClass.h"
#include "MyString.h"
#include "Vector.hpp"

namespace HotelCommands
{
	class CheckinCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class AvailabilityCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class CheckoutCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class ReportCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class FindCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	/*class FindUrgentCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};*/

	class UnavailableCommand : public Command {
	public:
		void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

};