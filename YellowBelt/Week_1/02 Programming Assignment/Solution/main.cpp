#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

// int unsigned
// size_t

// int8_t uint8_t
// int16_t uint16_t
// int32_t uint32_t
// int64_t uint64_t

// sizeof()
// numeric_limits<Type>::min() or max()

// static_cast<int>vector.size()

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> temperatures(num);
    int64_t sum = 0;
    for (int& temperature : temperatures) {
        cin >> temperature;
        sum += temperature;
    }

    int64_t average = sum / num;
    vector<int> result_indicies;
    for (int i = 0; i < num; ++i) {
        if (temperatures[i] > average) {
            result_indicies.push_back(i);
        }
    }

    cout << result_indicies.size() << endl;
    for (int& result_index : result_indicies) {
        cout << result_index << " ";
    }
    cout << endl;

    return 0;
}