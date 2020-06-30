#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person {
  string name;
  string surname;
  int age;
};

int main() {
  int x = 5;
  double pi = 3.14;
  bool logical_value = false;
  char symbol = 'Z';

  string hw = "Hello, World!";
  vector<int> nums = {1, 2, 3, 4, 5};
  
  map<string, int> name_to_value;
  name_to_value["one"] = 1;
  name_to_value["two"] = 2;

  vector<Person> staff;
  staff.push_back({"Alex", "Adams", 39});
  staff.push_back({"June", "Adams", 39});

  cout << staff[1].surname;

  return 0;
}
