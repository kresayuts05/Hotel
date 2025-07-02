#pragma once
#include "MyString.h"

//взето от StackOverflow
class Date {
private:
    unsigned year;
    unsigned month;
    unsigned day;

    bool isLeapYear(unsigned y) const;
    unsigned daysInMonth(unsigned m, unsigned y) const;
    bool isValid() const;

public:
    Date();
    Date(unsigned y, unsigned m, unsigned d);
    Date(const MyString& iso); // ISO формат: YYYY-MM-DD

    MyString toString() const;
    int daysUntil(const Date& other) const;

   static Date parse(const char* str);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
};
