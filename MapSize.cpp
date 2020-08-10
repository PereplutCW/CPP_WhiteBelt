#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
  m[2] = "two";
  cout << m.size();
  m.erase(1);
  cout << m.size();
  m[3] = "three";
  cout << m.size();
  m.erase(4);
  cout << m.size();
  m[5] = "five";
  cout << m.size();

  return 0;
}
