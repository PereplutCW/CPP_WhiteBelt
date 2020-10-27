#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

// Объявление шаблонных функций

template <typename Collection>
string Join(const Collection& cont, char sep);

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v);

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m);

template<typename Collection> Collection Sqr(const Collection& collection);

template<typename First, typename Second> 
pair<First, Second> Sqr(const pair<First, Second>& init_pair);

template<typename Element>
vector<Element> Sqr(const vector<Element>& init_vector);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& init_map);

// Реализация шаблонных функций

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

template <typename Collection>
Collection Sqr(const Collection& collection) {
    return collection * collection;
}

template<typename First, typename Second> 
pair<First, Second> Sqr(const pair<First, Second>& init_pair) {
    return {Sqr(init_pair.first), Sqr(init_pair.second)};
}

template<typename Element>
vector<Element> Sqr(const vector<Element>& init_vector) {
    vector<Element> result_vector;
    for (const auto& element : init_vector) {
        result_vector.push_back(Sqr(element));
    }
    return result_vector;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& init_map) {
    map<Key, Value> result_map;
    for (const auto& item : init_map) {
        result_map[item.first] = Sqr(item.second);
    }
    return result_map;
}

int main() {
    vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}    
    return 0;
}