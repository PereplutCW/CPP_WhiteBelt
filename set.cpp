#include <iostream>
#include <set>

using namespace std;

void PrintSet(const set<string>& s) {
  cout << "Size = " << s.size() << endl;
  for (auto x : s) {
    cout << x << endl;
  }
}
int main() {
  set<string> letters;
  letters.insert("A");
  letters.insert("B");
  letters.insert("c");
  PrintSet(letters);

  return 0;
}
