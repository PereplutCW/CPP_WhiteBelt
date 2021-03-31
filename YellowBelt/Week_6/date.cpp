#include <date.h>

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

Date ParseDate(istream& stream) {
    int year = 0;
    int month = 0;
    int day = 0;

    string date;
    string error_message = "Wrong date format: " + date;

    stream >> date;

    stringstream stream_date(date);

    stream_date >> year;
    if (stream_date.fail() || stream_date.peek() != '-') {
        throw runtime_error(error_message);
    }
    stream_date.ignore();

    stream_date >> month;
    if (stream_date.fail() || stream_date.peek() != '-') {
        throw runtime_error(error_message);
    }
    stream_date.ignore();

    stream_date >> day;
    if (stream_date.fail() || !stream_date.eof()) {
        throw runtime_error(error_message);
    }

    return Date(year, month, day);
}

ostream& operator<< (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-'
           << setw(2) << setfill('0') << date.GetDay();
    
    return stream;
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

//map<Date, pair<set<string>, vector<set<string>::iterator>>> db;

