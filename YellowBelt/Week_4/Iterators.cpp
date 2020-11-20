#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Lang {
    string name;
    int age;
};

ostream& operator<<(ostream& stream, const Lang& lang) {
    stream << lang.name << " " << lang.age << endl;
    return stream;
}

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin;
        it != range_end;
        ++it) {
        cout << *it << " ";
    }
}

int main() {
    vector<Lang> langs = {
        {"C", 45},
        {"C++", 34},
        {"Python", 26},
        {"Java", 22},
        {"C#", 17}
    };   

    set<string> lang_names = {"C", "C++", "Python", "Java", "C#"};

    auto it = lang_names.find("Python");

    PrintRange(begin(lang_names), it);

    /*
    auto result = find_if(
        begin(langs), end(langs),
        [](const Lang& lang) {
            return lang.name[0] == 'P';
        }
    );
    
    if (result == end(langs)) {
        cout << "Not found!" << endl;
    } else { 
        cout << result->age << endl;
    }
    
    string lang = langs[1].name;
    auto it = lang.begin();
    cout << *it;
    ++it;
    cout << *it;
    */

    return 0;
}