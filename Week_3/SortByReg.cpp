#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> strings;

    int quantityNumbers;
    cin >> quantityNumbers;

    for (int i = 0; i < quantityNumbers; ++i) {
        string str, newStr;
        cin >> str;
        
        strings.push_back(str);
    }

    sort(begin(strings), end(strings), 
         [](const string& l, const string& r) {
             return lexicographical_compare(begin(l), end(l), begin(r), end(r), 
             [](char cl, char cr) {
                 return tolower(cl) < tolower(cr);
             });
         });

    for (const auto& item : strings) {
        cout << item << ' ';
    }

    return 0;
}