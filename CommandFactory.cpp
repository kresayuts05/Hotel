#include "CommandFactory.h"
#include "TerminalCommands.h"
#include "HotelCommands.h"
#include <stdexcept>


Command* CommandFactory::create(const MyString& name) {
//using namespace TerminalCommands;
//using namespace HotelCommands;
    // terminal
    if (name == "open")         return new TerminalCommands::OpenCommand();
    else if (name == "close")        return new TerminalCommands::CloseCommand();
    else if (name == "save")         return new TerminalCommands::SaveCommand();
    else if (name == "saveas") return new TerminalCommands::SaveAsCommand();
    else if (name == "help")         return new TerminalCommands::HelpCommand();
    else if (name == "exit")         return new TerminalCommands::ExitCommand();

    // hotel
    else if (name == "checkin")      return new HotelCommands::CheckinCommand();
    else if (name == "availability") return new HotelCommands::AvailabilityCommand();
    else if (name == "checkout")     return new HotelCommands::CheckoutCommand();
    else if (name == "report")       return new HotelCommands::ReportCommand();
    else if (name == "find")         return new HotelCommands::FindCommand();
   /* else if (name == "find!")        return new HotelCommands::FindUrgentCommand();*/
    else if (name == "unavailable")  return new HotelCommands::UnavailableCommand();

    throw std::invalid_argument("Unknown command!");
}