#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Lang {
    string name;
    string implementation;
};

ostream& operator<<(ostream& stream, const Lang& lang) {
    stream << lang.name << " " << lang.implementation << endl;
    return stream;
}

template <typename It>
void PrintRange(It range_begin, It range_end, const string& title) {
    cout << title;
    for (auto it = range_begin;
        it != range_end;
        ++it) {
        cout << it->name << " ";
    }
    cout << endl;
}

int main() {
    vector<Lang> langs = {
        {"C/C++", "Compiled"},
        {"Rust", "Compiled"},
        {"Python", "Interpreted"},
        {"JavaScript", "Interpreted"}
    };   

    vector<Lang> interpreted_langs;
    vector<Lang> compiled_langs;

    copy_if(begin(langs), end(langs), back_inserter(interpreted_langs),
            [](const Lang& lang) {
        return lang.implementation == "Interpreted";
    });

    copy_if(begin(langs), end(langs), back_inserter(compiled_langs),
            [](const Lang& lang) {
        return lang.implementation == "Compiled";
    });

    PrintRange(begin(langs), end(langs), "All langs: ");
    PrintRange(begin(interpreted_langs), end(interpreted_langs), "Interpreted langs: ");
    PrintRange(begin(compiled_langs), end(compiled_langs), "Compiled langs: ");

    cout << "MW" << 'V';

    return 0;
}