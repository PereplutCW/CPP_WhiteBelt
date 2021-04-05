#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>

using namespace std;

struct Operation {
  char type = 0;
  int number = 0;
};

bool NeedBrackets(char last, char current) {
  return (last == '+' || last == '-') && (current == '*' || current == '/');
}

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
  char last_type = '*';
  for (const auto& operation : operations) {
    if (NeedBrackets(last_type, operation.type)) {
      expression.push_front("(");
      expression.push_back(")");
    }
    expression.push_back(" ");
    expression.push_back(string(1, operation.type));
    expression.push_back(" ");
    expression.push_back(to_string(operation.number));

    last_type = operation.type;
  }

  for (const string& str : expression) {
    cout << str;
  }

  return 0;
}