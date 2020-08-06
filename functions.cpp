#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  const string s = "Hello";
  string t = s;
  t += ", World!";
  cout << t;

  return 0;
}
