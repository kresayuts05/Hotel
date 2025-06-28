#include "CommandHandler.h"

CommandHandler::CommandHandler() : commandCount(0) {}

CommandHandler::~CommandHandler() {
    for (int i = 0; i < commandCount; ++i) {
        delete commands[i];
    }
}

void CommandHandler::registerCommand(Command* cmd) {
    if (commandCount < MAX_COMMANDS) {
        commands[commandCount++] = cmd;
    }
    else {
        //TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        throw;
    }
}

