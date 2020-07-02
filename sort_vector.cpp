#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
  vector<string> nums = {"1", "2", "3", "4", "5+"};
  for (auto c : nums) {
    cout << c << ",";
  }

  return 0;
}
