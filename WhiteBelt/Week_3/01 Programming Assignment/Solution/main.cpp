#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool sortByAbs(int a, int b) {
    if (abs(a) < abs(b)) {
        return true;
    } 
    return false;
}

int main() {
    vector<int> nums;

    int quantityNumbers;
    cin >> quantityNumbers;

    for (int i = 0; i < quantityNumbers; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(begin(nums), end(nums), sortByAbs);

    for (const auto& i : nums) {
        cout << i << ' ';
    }

    return 0;
}