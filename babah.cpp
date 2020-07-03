#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string word = "babah";
  sort(begin(word), end(word));
  cout << word << " " << count(begin(word), end(word), 'b');

  return 0;
}
