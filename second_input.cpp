#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string str;
  
  cin >> str;

  int quantity = count(begin(str), end(str), 'f');

  if (quantity == 0) {
    cout << -2 << endl;
  } else if (quantity == 1) {
    cout << -1 << endl;
  } else if (quantity > 1) {
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == 'f') {
        count += 1;
        if (count == 2) {
          cout << i << endl;
          break;
        }
      }
    }
  }
  

  return 0;
}
