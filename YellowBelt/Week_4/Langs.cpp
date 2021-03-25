#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " ";
    }
}

int main() {
    vector<string> langs = {
        "C",
        "C++",        
        "Python",
        "Java",
        "C#"
    };   

    auto border = find(langs.begin(), langs.end(), "Python");
    langs.erase(border, langs.end());
    langs.insert(langs.end(), {"Python", "Java", "C#"});

    vector<string> c_langs;
    copy_if(langs.begin(), langs.end(), back_inserter(c_langs),
           [](const string& lang) {
               return lang[0] == 'C';
           });

    PrintRange(langs.begin(), langs.end());
    cout << endl;
    PrintRange(c_langs.begin(), c_langs.end());

    return 0;
}