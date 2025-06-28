#pragma once

#include "MyString.h"

class Guest {
public:
    Guest(MyString name, MyString egn, MyString phone);

    MyString getName() const;
    MyString getEgn() const;
    MyString getPhone() const;

    MyString toString() const;

private:
    MyString name;
    MyString egn;
    MyString phone;
};

