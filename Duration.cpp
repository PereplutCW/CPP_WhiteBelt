#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int minute;

    Duration(int h = 0, int m = 0) {
        int total  = h * 60 + m;
        hour = total / 60;
        minute = total % 60;
    }
};

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.minute;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' 
           << setw(2) << duration.minute;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.minute + rhs.minute);
}

bool operator<(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.minute < rhs.minute;
    }
    return lhs.hour < rhs.hour;
}

void PrintVector(const vector<Duration>& durs) {
    for (const auto& dur : durs) {
        cout << dur << ' ';
    }
    cout << endl;
}

int main() {
    stringstream durSs("1:50");
    Duration dur1;
    durSs >> dur1;
    Duration dur2 = {0, 35};
    Duration dur3 = dur1 + dur2;
    vector<Duration> durs = {dur3, dur1, dur2};

    PrintVector(durs);
    sort(begin(durs), end(durs));
    PrintVector(durs);

    return 0;
}