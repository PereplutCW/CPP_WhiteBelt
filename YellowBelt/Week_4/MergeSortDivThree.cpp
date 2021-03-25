#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }

    vector<typename RandomIt::value_type> elements(range_begin, range_end);

    auto one_third = elements.begin() + range_length / 3;
    auto two_third = elements.begin() + range_length * 2 / 3;

    MergeSort(elements.begin(), one_third);
    MergeSort(one_third, two_third);
    MergeSort(two_third, elements.end());

    vector<typename RandomIt::value_type> inter_result;
    merge(elements.begin(), one_third, one_third, two_third, back_inserter(inter_result));    
    merge(inter_result.begin(), inter_result.end(), two_third, elements.end(), range_begin); 
};

int main() {
    vector<int> nums = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(nums.begin(), nums.end());
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}