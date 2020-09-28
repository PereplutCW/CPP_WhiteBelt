#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto s : source) {
    destination.push_back(s);
  }
  source.clear();

  return destination;
}

