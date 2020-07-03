#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> nums = {1, 2, 5, 3, 4, 5, 6, 7, 5, 8, 9, 0};
int quantity = count(begin(nums), end(nums), 5);
cout << "There is " << quantity << " fives";
return 0;
}
