#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <string>

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key& k) {
    if (m.count(k) == 0) {
        throw runtime_error("Error");
    };
    return m.at(k);
}

int main() {

    return 0;
}