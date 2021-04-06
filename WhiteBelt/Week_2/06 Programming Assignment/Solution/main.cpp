#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n / 2; ++i) {
    int tmp = v[i];
    v[i] = v[n - 1 - i];
    v[n - 1 - i] = tmp;
  }
}

vector<int> Reversed(const vector<int>& v) {
  vector<int> result = v;
  Reverse(result);

  return result;
}

