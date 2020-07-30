#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double A, B, C, D, X1, X2;
  cin >> A >> B >> C;
  D = B * B - (4 * A * C);

  if (D > 0) {
    X1 = (B * -1 + sqrt(D)) / A * 2;
    X2 = (B * -1 - sqrt(D)) / A * 2;
    cout << X1 << ' ' << X2;
  } else if (D == 0) {
    X1 = B * -1 / A * 2;
    cout << X1;
  } else {
    cout << ' ';
  }
  
  return 0;
}
