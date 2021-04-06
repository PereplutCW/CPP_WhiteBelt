#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
    int size;
    cin >> size;
    vector<int> permutation(size);

    iota(permutation.begin(), permutation.end(), 1);
    reverse(permutation.begin(), permutation.end());

    do {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    } while (prev_permutation(permutation.begin(), permutation.end()));

    return 0;
}