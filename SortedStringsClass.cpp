#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
    public:
    void AddString(const string& str) {
        // добавить строку str в набор
        strings.push_back(str);
    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(begin(strings), end(strings));
        return strings;
    }
    private:
    // приватные поля
    vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const auto& string : strings.GetSortedStrings()) {
        cout << string << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    return 0;
}