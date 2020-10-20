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
    unsigned num, density;
    cin >> num >> density;

    vector<uint64_t> volumes(num);
    for (unsigned i = 0; i < num; ++i) {
        unsigned x, y;
        uint64_t z;
        cin >> x >> y >> z;
        uint64_t volume = x * y * z;
        volumes.push_back(volume);
    }

    uint64_t sum_mass = 0;
    for (uint64_t& volume : volumes) {
        uint64_t mass = volume * density;
        sum_mass += mass;
    }

    if (num == 0 || density == 0) {
        cout << 0 << endl;
    } else {
        cout << sum_mass << endl;
    }    

    return 0;
}