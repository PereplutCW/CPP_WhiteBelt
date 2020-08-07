#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintVector(const vector<string>& v) {
  for (string s : v) {
    cout << s << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (string& s : v) {
    cin >> s;
  }
  PrintVector(v);

  return 0;
}
