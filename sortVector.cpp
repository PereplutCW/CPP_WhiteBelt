#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Sort(vector<int>& v) {
  sort(begin(v), end(v));
}

int main() {
  int num;
  vector<int> nums;

  cin >> num;

  while (num != 0) {
    nums.push_back(num);
    cin >> num;
  }

  Sort(nums);

  for (auto x : nums) {
    cout << x << ' ';
  }

  return 0;
}
