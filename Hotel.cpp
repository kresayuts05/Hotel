#include <iostream>
#include "HotelClass.h"
#include "Command.h"
#include "CommandFactory.h"
#include "MyString.h"
#include "Vector.hpp"


//ПОМОЩНИ ФУНКЦИИ
void welcome() {
	std::cout << std::endl << "Hello!" << std::endl
		<< "Write 'help' to see all the options for commands." << std::endl;
}

// Чете ред от конзолата и го връща като референция към статичен MyString
MyString& readLine() {
	static char buffer[1024];
	std::cin.getline(buffer, 1024);

	static MyString result;
	result = MyString(buffer);
	return result;
}

// Разбива MyString по интервали и записва резултата в подаден Vector
void tokenize(const MyString& line, Vector<MyString>& outTokens) {
	outTokens.clear();
	size_t len = line.length();
	size_t start = 0;

	while (start < len) {
		while (start < len && line[start] == ' ') {
			++start;
		}

		if (start == len) break;

		size_t end = start;
		while (end < len && line[end] != ' ') {
			++end;
		}

		size_t wordLen = end - start;
		char* wordBuffer = new char[wordLen + 1];
		for (size_t i = 0; i < wordLen; ++i) {
			wordBuffer[i] = line[start + i];
		}
		wordBuffer[wordLen] = '\0';

		outTokens.push_back(MyString(wordBuffer));
		delete[] wordBuffer;

		start = end;
	}
}

//ПРОГРАМКАТА
int main() {
	HotelClass hotel;
	Vector<MyString> args;

	welcome();

	while (true) {
		std::cout << std::endl << "> ";
		MyString& line = readLine();
		tokenize(line, args);

		if (args.getSize() == 0) {
			continue;
		}

		try {
			Command* command = CommandFactory::create(args[0]);
			command->execute(args, hotel);
			delete command;
		}
		catch (const std::exception& e) {
			std::cout << "Error:  " << e.what() << '\n';
		}
	}
}


