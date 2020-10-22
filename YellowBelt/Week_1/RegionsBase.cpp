#include <iostream>
#include <tuple>
#include <utility>
#include <map>
#include <set>

using namespace std;

struct Date {
    int year;
    string month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
        return tie(lhs.year, lhs.month, lhs.day) < 
               tie(lhs.year, lhs.month, lhs.day);
}

class Cities {
public:
    tuple<bool, string> FindCountry(const string& sity) const {
        if (city_to_country.count(sity)) {
            return {true, city_to_country.at(sity)};
        } else if (ambiguous_cities.count(sity)) {
            return {false, "Ambiguous"};
        } else {
            return {false, "Not exist"};
        }
    };
private:
    map<string, string> city_to_country;
    set<string> ambiguous_cities;
};

int main() {

    // tuple t(7, "C++", true);
    // auto t = make_tuple(7, "C++", true);

    // pair p(17, "C++");

    Cities cities;
    auto [success, message] = cities.FindCountry("Volgograd");

    cout << success << " " << message << endl;
    // cout << get<1>(p) << endl;
    // cout << p.first << " " << p.second << endl;

    return 0;
}