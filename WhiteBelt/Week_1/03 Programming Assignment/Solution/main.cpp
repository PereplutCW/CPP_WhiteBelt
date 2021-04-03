#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double A, B, C, D, X, X1, X2;
  cin >> A >> B >> C;

  if ((A != 0) && (B != 0) && (C != 0)) {
    D = (B * B) - (4 * A * C);
    if (D > 0) {
      X1 = (-B + sqrt(D)) / (2 * A);
      X2 = (-B - sqrt(D)) / (2 * A);
      cout << X1 << ' ' << X2;
    } else if (D == 0) {
      X1 = -B / (2 * A);
      cout << X1;
    }
  } else if ((A != 0) && (B == 0) && (C == 0)) {
      X = 0;
      cout << X;
  } else if (((A > 0) && (B == 0) && (C < 0)) || ((A < 0) && (B == 0) && (C > 0))) {
      X1 = sqrt(-C / A);
      X2 = -sqrt(-C / A);
      cout << X1 << ' ' << X2;  
  } else if ((A != 0) && (B != 0) && (C == 0)) {
      X1 = 0;
      X2 = -(B / A);
      cout << X1 << ' ' << X2;
  } else if ((A == 0) && (B != 0) && (C != 0)) {
      X = -(C / B);
      cout << X;
  } else {
      cout << ' ';
  }
  
  return 0;
}
