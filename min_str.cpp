#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  if (a > b) {
    a = b;
    if (b > c) {
      a = c;
    }
  } else {
    if (a > c) {
      a = c;
    }
  }

  cout << a;
  return 0;
}
