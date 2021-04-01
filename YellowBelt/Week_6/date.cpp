#include "date.h"

Date::Date() noexcept : year(0), month(0), day(0) {}

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month < 1 || new_month > 12) {
        string error_message = "Month value is invalid: " + to_string(new_month);
        throw runtime_error(error_message);
    } else if (new_day < 1 || new_day > 31) {
        string error_message = "Day value is invalid: " + to_string(new_day);
        throw runtime_error(error_message);
    } else {
        month = new_month;
        day = new_day;
    }
}

int Date::GetYear() const noexcept {
    return year;
}

int Date::GetMonth() const noexcept {
    return month;
}

int Date::GetDay() const noexcept {
    return day;
}

string Date::DateToString() const {
    streamstring ss;
    ss << *this;
    return ss.str();
}

Date ParseDate(istream& is) {
    int year = 0;
    int month = 0;
    int day = 0;

    string date;
    string error_message = "Wrong date format: " + date;

    is >> date;

    stringstream ss_date(date);

    ss_date >> year;
    if (ss_date.fail() || ss_date.peek() != '-') {
        throw runtime_error(error_message);
    }
    ss_date.ignore();

    ss_date >> month;
    if (ss_date.fail() || ss_date.peek() != '-') {
        throw runtime_error(error_message);
    }
    ss_date.ignore();

    ss_date >> day;
    if (ss_date.fail() || !ss_date.eof()) {
        throw runtime_error(error_message);
    }

    return Date(year, month, day);
}

ostream& operator<< (ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-'
           << setw(2) << setfill('0') << date.GetDay();
    
    return os;
}

bool operator< (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator<= (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator> (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>= (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator== (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator!= (const Date& lhs, const Date& rhs) noexcept {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != 
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}