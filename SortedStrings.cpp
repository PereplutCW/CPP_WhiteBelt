#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
    public:
    void AddStrings(const string& str) {
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

    strings.AddStrings("First");
    strings.AddStrings("Third");
    strings.AddStrings("Second");
    PrintSortedStrings(strings);

    strings.AddStrings("Second");
    PrintSortedStrings(strings);

    return 0;
}