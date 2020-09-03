#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadAll(const string& path) {
  ifstream input(path);
  if (input) {
    string line;
    while (getline(input, line)) {
      cout << line;
    }

  }
}

int main() {
  const string path = "output.txt";
  ofstream output(path, ios::app);
  output << " , World!" << endl;
  
  ReadAll(path);

  return 0;
}
