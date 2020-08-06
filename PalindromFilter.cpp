#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string str) {
  for (int i = 0; i < str.size() / 2; ++i) {
    if (str[i] != str[str.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
  vector<string> palindroms;
  for (auto x : words) {
    if (IsPalindrom(x) && x.size() >= minLength) {
      palindroms.push_back(x);
    }
  }
  return palindroms;
}

int main() {
  vector<string> words = {"weew", "bro", "code"};
  int minLength = 2;

  vector<string> result = PalindromFilter(words, 2);

  return 0;
}
