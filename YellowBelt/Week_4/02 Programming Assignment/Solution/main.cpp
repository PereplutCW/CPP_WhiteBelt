#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    auto it = elements.begin();
    while(it != elements.end() && *it <= border) {
        it++;
    }
    return {it, elements.end()};
};

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;
  
    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}