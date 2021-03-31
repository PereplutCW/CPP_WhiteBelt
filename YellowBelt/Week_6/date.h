#pragma once

#ifndef _DATE_H_
#define _DATE_H_

#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <memory>

using namespace std;

class Date {
public:
    Date() noexcept;
    Date(int new_year, int new_month, int new_day);

    int GetYear() const noexcept;
    int GetMonth() const noexcept;
    int GetDay() const noexcept;
    string DateToString() const;
private:
    int year;
    int month;
    int day;
}

Date ParseDate(istream& stream);

ostream& operator<< (ostream& os, const Date& date);

bool operator< (const Date& lhs, const Date& rhs) noexcept;
bool operator<= (const Date& lhs, const Date& rhs) noexcept;
bool operator> (const Date& lhs, const Date& rhs) noexcept;
bool operator>= (const Date& lhs, const Date& rhs) noexcept;
bool operator== (const Date& lhs, const Date& rhs) noexcept;
bool operator!= (const Date& lhs, const Date& rhs) noexcept;

#endif;