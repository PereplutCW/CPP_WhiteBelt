#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int num, remain;
  vector<int> bin_num;

  cin >> num;
  
  while (num > 0) {
    remain = num % 2;
    bin_num.push_back(remain);
    num = num / 2;
  }  

  reverse(bin_num.begin(), bin_num.end());

  for (auto i : bin_num) {
    cout << i;
  };

  return 0;
}
