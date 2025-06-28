#include "Guest.h"


Guest::Guest(MyString name, MyString egn, MyString phone)
	: name(name), egn(egn), phone(phone) {}

MyString Guest::getName() const {
	return name;
}

MyString Guest::getEgn() const {
	return egn;
}

MyString Guest::getPhone() const {
	return phone;
}

MyString Guest::toString() const {
	return name + "," + egn + "," + phone;
}