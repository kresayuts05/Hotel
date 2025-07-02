#include "TerminalCommands.h"
#include "Vector.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace TerminalCommands;

void OpenCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
    if (args.getSize() < 2) {
        throw std::invalid_argument("Incorrect format. Format: open <filename>");
    }

    hotel.loadFromFile(args[1]);
}

void CloseCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
    hotel.free();
    hotel.setOpenedFileName("");
    std::cout << "File closed." << std::endl;
}

void SaveCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
    const MyString& file = hotel.getOpenedFileName();
    if (file.length() == 0) {
        throw std::logic_error("No file for writing.");
    }

    hotel.saveToFile(file);
}

void SaveAsCommand::execute(const Vector<MyString>& args, HotelClass& hotel) {
    if (args.getSize() < 2) {
        throw std::invalid_argument("Incorrect format. Format: saveas <filename>");
    }

    hotel.saveToFile(args[1]);
    hotel.setOpenedFileName(args[1]);
}

void HelpCommand::execute(const Vector<MyString>&, HotelClass&) {
    std::cout <<
        "All commands:" << std::endl <<
        " open <file>" << std::endl <<
        " close" << std::endl <<
        " save" << std::endl <<
        " saveas <file>" << std::endl <<
        " checkin <room> <from> <to> <note> [<guests>]" << std::endl <<
        " availability [<date>]" << std::endl <<
        " checkout <room>" << std::endl <<
        " report <from> <to>" << std::endl <<
        " find <beds> <from> <to>" << std::endl <<
        " find! <beds> <from> <to>" << std::endl <<
        " help" << std::endl <<
        " exit" << std::endl;
}

void ExitCommand::execute(const Vector<MyString>&, HotelClass&) {
    std::cout << "Goodbye." << std::endl;
    exit(0);
}