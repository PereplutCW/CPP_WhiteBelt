#include <iostream>
#include <sstream>
#include <utility>
#include <set>
#include <vector>
#include <map>

using namespace std;

// Предварительное объявление шаблонных функций

template <typename Collection>
string Join(const Collection& cont, char sep);

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v);

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m);

template<typename First, typename Second> 
pair<First, Second> operator*(const pair<First, Second>& first_pair, 
                              const pair<First, Second>& second_pair);

template<typename Element> 
vector<Element> operator*(const vector<Element>& first_vector,
                          const vector<Element>& second_vector);

template<typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& first_map,
                          const map<Key, Value>& second_map);

template<typename Collection> Collection Sqr(const Collection& collection);

/*

template<typename First, typename Second> 
pair<First, Second> Sqr(const pair<First, Second>& init_pair);

template<typename Element>
vector<Element> Sqr(const vector<Element>& init_vector);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& init_map);

*/

// Объявление шаблонных функций

// Объявление функции Join для вывода в поток элементов контейнера

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

// Переопределение оператора << для типа Pair

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
    out << '(' << p.first << "," << p.second << ')';
    return out;
}

// Переопределение оператора << для типа Vector

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << '[' << Join(v, ',') << ']';
}

// Переопределение оператора << для типа Map

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ',') << '}';
}

// Переопределение оператора * для типа Pair

template<typename First, typename Second> 
pair<First, Second> operator*(const pair<First, Second>& first_pair, 
                              const pair<First, Second>& second_pair) {
    // pair<First, Second> result_pair;
    First first = first_pair.first * second_pair.first;
    Second second = first_pair.second * second_pair.second;
    return {first, second};
};

// Переопределение оператора * для типа Vector

template<typename Element> 
vector<Element> operator*(const vector<Element>& first_vector,
                          const vector<Element>& second_vector) {
    vector<Element> result_vector;
    for (int i = 0; i < first_vector.size(); i++) {
        Element result_element = first_vector[i] * second_vector[i];
        result_vector.push_back(result_element);
    }
    return result_vector;
};

// Переопределение оператора * для типа Map

template<typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& first_map,
                          const map<Key, Value>& second_map) {
    map<Key, Value> result_map;
    for (const auto& item : first_map) {
        Key result_key = item.first;
        Value result_value = item.second * item.second;
        result_map.insert({result_key, result_value});
    }
    return result_map;
}

// Объявление функции Collection для возведения элементов контейнера во вторую степень

template <typename Collection>
Collection Sqr(const Collection& collection) {
    Collection result_collection = collection * collection;
    return result_collection;
}

/*

template<typename First, typename Second> 
pair<First, Second> Sqr(const pair<First, Second>& init_pair) {
    pair<First, Second> result_pair;
    result_pair.first = init_pair.first * init_pair.first;
    result_pair.second = init_pair.second * init_pair.second;
    return result_pair;
}

template<typename Element>
vector<Element> Sqr(const vector<Element>& init_vector) {
    vector<Element> result_vector;
    for (const auto& element : init_vector) {
        Element result_element = element * element;
        result_vector.push_back(result_element);
    }
    return result_vector;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& init_map) {
    map<Key, Value> result_map;
    for (const auto& item : init_map) {
        Key result_key = item.first;
        Value result_value = item.second * item.second;
        result_map.insert({result_key, result_value});
    }
    return result_map;
}

*/

int main() {
    pair<int, int> p1 = {1, 2};
    pair<vector<int>, double> p2 = {{1, 2, 3}, 3.5};
    vector<int> v1 = {1, 2, 3};
    vector<vector<int>> v2 = {{1, 2}, {3, 4}, {5, 6}};
    map<int, vector<int>> m = {{1, {1, 2, 3}}, {2, {2, 3, 4}}, {3, {4, 5, 6}}};

    cout << Sqr(p1) << endl;
    return 0;
}