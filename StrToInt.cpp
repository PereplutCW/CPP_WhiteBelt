#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getCommandNumber(string& commandInput) {
  string commandNumberString;
  for (int i = commandInput.size() - 1; commandInput[i] != ' '; --i) {
    commandNumberString += commandInput[i];
  }
  reverse(commandNumberString.begin(), commandNumberString.end());
  int commandNumberInt = stoi(commandNumberString);
  return commandNumberInt;
}

int main() {
  string commandInput = "COME -25";
  string commandWord;
  for (int i = 0; commandInput[i] != ' '; ++i) {
    commandWord += commandInput[i];
  }
  int commandNumber = getCommandNumber(commandInput);
  cout << commandWord << endl;
  cout << commandNumber;

  return 0;
}
