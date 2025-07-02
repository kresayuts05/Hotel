#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include <stdexcept>
#include <cstdio>


//взето от StackOverflow
Date::Date() : year(2000), month(1), day(1) {}

Date::Date(unsigned y, unsigned m, unsigned d)
	: year(y), month(m), day(d) {

	/*std::cout << y << " " << m << " " << d << std::endl;*/
	if (!isValid())
		throw std::invalid_argument("Invalid data.");
}

Date Date::parse(const char* str) {
	/*std::cout << " Parsing: [" << str << "]\n";*/

	int year, month, day;
	int result = std::sscanf(str, "%4d-%2d-%2d", &year, &month, &day);
	//std::cout << "sscanf returned: " << result << std::endl;

	if (result != 3) {
		throw std::runtime_error("Invalid data (expected YYYY-MM-DD)");
	}

	return Date(year, month, day);
}

Date::Date(const MyString& iso) {
	if (iso.length() != 10 || iso[4] != '-' || iso[7] != '-')
		throw std::invalid_argument("Invalid iso format.");

	year = (iso[0] - '0') * 1000 + (iso[1] - '0') * 100 +
		(iso[2] - '0') * 10 + (iso[3] - '0');
	month = (iso[5] - '0') * 10 + (iso[6] - '0');
	day = (iso[8] - '0') * 10 + (iso[9] - '0');

	if (!isValid())
		throw std::invalid_argument(std::string("Invalid data: ") + iso.c_str());
}

bool Date::isLeapYear(unsigned y) const {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

unsigned Date::daysInMonth(unsigned m, unsigned y) const {
	static const unsigned d[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (m == 2 && isLeapYear(y)) ? 29 : d[m - 1];
}

bool Date::isValid() const {
	if (month < 1 || month > 12) {
		return false;
	}

	if (day < 1 || day > daysInMonth(month, year)) {
		return false;
	}

	return true;
}

MyString Date::toString() const {
	char buffer[11];
	buffer[0] = '0' + (year / 1000) % 10;
	buffer[1] = '0' + (year / 100) % 10;
	buffer[2] = '0' + (year / 10) % 10;
	buffer[3] = '0' + year % 10;
	buffer[4] = '-';
	buffer[5] = '0' + (month / 10);
	buffer[6] = '0' + (month % 10);
	buffer[7] = '-';
	buffer[8] = '0' + (day / 10);
	buffer[9] = '0' + (day % 10);
	buffer[10] = '\0';
	return MyString(buffer);
}

int Date::daysUntil(const Date& other) const {
	auto daysSinceStart = [](const Date& d) {
		int days = d.day;
		for (unsigned y = 1; y < d.year; ++y)
			days += (d.isLeapYear(y) ? 366 : 365);
		for (unsigned m = 1; m < d.month; ++m)
			days += d.daysInMonth(m, d.year);
		return days;
		};

	int d1 = daysSinceStart(*this);
	int d2 = daysSinceStart(other);
	return d2 - d1;
}

bool Date::operator==(const Date& o) const {
	return year == o.year && month == o.month && day == o.day; 
}

bool Date::operator!=(const Date& o) const { 
	return !(*this == o); 
}

bool Date::operator<(const Date& o) const {
	if (year != o.year) return year < o.year;
	if (month != o.month) return month < o.month;
	return day < o.day;
}

bool Date::operator<=(const Date& o) const {
	return *this < o || *this == o; 
}

bool Date::operator>(const Date& o) const {
	return !(*this <= o); 
}

bool Date::operator>=(const Date& o) const {
	return !(*this < o); 
}