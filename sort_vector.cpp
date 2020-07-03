#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {1, 2, 5, 3, 4, 5, 6, 7, 5, 8, 9, 0};
  sort(begin(nums), end(nums));
  for (auto x : nums) {
    cout << x << " ";
  }

  return 0;
}
