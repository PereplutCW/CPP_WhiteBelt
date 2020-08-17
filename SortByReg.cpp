#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool sortByReg(string a, string b) {
    if (tolower(a) < tolower(b)) {
        return true;
    } 
    return false;
}

int main() {
    vector<string> strings;

    int quantityNumbers;
    cin >> quantityNumbers;

    for (int i = 0; i < quantityNumbers; ++i) {
        string str;
        cin >> str;
        strings.push_back(str);
    }

    sort(begin(strings), end(strings), sortByReg);

    for (const auto& i : strings) {
        cout << i << ' ';
    }

    return 0;
}