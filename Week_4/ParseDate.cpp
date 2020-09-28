#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        ss << "expected /, but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }    
    stream.ignore(1);
}

Date ParseDate(const string& str) {
    stringstream stream(str);
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

int main() {
    string dateStr = "2020/09b09";
    try {
        Date date = ParseDate(dateStr);
        cout << setw(2) << setfill('0') << date.day << '.'
             << setw(2) << setfill('0') << date.month << '.'
             << date.year << endl;
    } catch (exception& ex) {
        cout << "Exception heppens: " << ex.what();
    }
    
    return 0;
}
