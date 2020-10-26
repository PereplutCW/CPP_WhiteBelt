#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

template <typename Collection>
string Join(const Collection& cont, char sep) {
    stringstream ss;
    bool first = true;
    for (const auto& i : cont) {
        if (!first) {
            ss << sep;
        }
        first = false;
        ss << i;        
    }
    return ss.str();
}

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    out << '(' << p.first << "," << p.second << ')';
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << '[' << Join(v, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ',') << '}';
}

int main() {
    /*
    auto p = make_pair(2, 3);
    auto res = sqr(p);
    cout << res.first << endl;
    cout << res.second << endl;
    */

    vector<vector<int>> v = {{1, 2, 3}, {4, 5}};
    cout << v << endl;
    
    map<int, double> m = {{1, 2.5}, {3, 4}};
    cout << m << " ";

    return 0;
}