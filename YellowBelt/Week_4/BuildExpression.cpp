#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct Operation {
  char type = 0;
  int number = 0;
};

int main() {
  int initial_number;
  cin >> initial_number;

  int operations_number;
  cin >> operations_number;
  vector<Operation> operations(operations_number);  // (*)
  for (int i = 0; i < operations_number; ++i) {
    cin >> operations[i].type;
    cin >> operations[i].number;
  }

  deque<string> expression;
  expression.push_back(to_string(initial_number));
  for (const auto& operation : operations) {
    expression.push_front("(");
    expression.push_back(") ");
    expression.push_back(string(1, operation.type));
    expression.push_back(" ");
    expression.push_back(to_string(operation.number));
  }

  for (const string& str : expression) {
    cout << str;
  }

  return 0;
}