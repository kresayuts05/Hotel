#pragma once

#include "Command.h"

class CommandHandler {
private:
    static const int MAX_COMMANDS = 10;
    Command* commands[MAX_COMMANDS];
    int commandCount;

public:
    CommandHandler();
    ~CommandHandler();

    void registerCommand(Command* cmd);
    void handle(const std::string& line);
};

