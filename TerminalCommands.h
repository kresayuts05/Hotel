#pragma once

#include "Command.h"
#include "HotelClass.h"
#include "MyString.h"
#include "Vector.hpp"

namespace TerminalCommands
{
	class OpenCommand : public Command {
	public:
		virtual void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class CloseCommand : public Command {
	public:
		virtual void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class SaveCommand : public Command {
	public:
		virtual void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class SaveAsCommand : public Command {
	public:
		virtual  void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class HelpCommand : public Command {
	public:
		virtual void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};

	class ExitCommand : public Command {
	public:
		virtual void execute(const Vector<MyString>& args, HotelClass& hotel) override;
	};
};

