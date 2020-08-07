#include <iostream>
#include <vector>

using namespace std;

int main() {
  int vectorSize;

  cin >> vectorSize;

  vector<int> temp(vectorSize);
  int tempSum = 0;

  for (int& i : temp) {
    cin >> i;
    tempSum += i;
  }
  int tempMean = tempSum / vectorSize;
  
  vector<int> index;  
  for (int i = 0; i < vectorSize; ++i) {
    if (temp[i] > tempMean) {
      index.push_back(i);
    }
  }
   
  cout << index.size() << endl;
  for (auto i : index) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}
