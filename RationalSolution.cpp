#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
 
using namespace std;
 
class Rational {
public:
  Rational()
{
      p = 0;
      q = 1;
}
  Rational(int numerator, int denominator)
  {
      if (numerator == 0)
      {
          p = 0;
          q = 1;
          return;
      }
 
      if ((numerator < 0) && (denominator < 0))
      {
          numerator = -numerator;
          denominator = -denominator;
      }
      else if (denominator < 0)
      {
          numerator = -numerator;
          denominator = -denominator;
      }
 
      int g = std::gcd(numerator, denominator);
      numerator /= g;
      denominator /= g;
 
      p = numerator;
      q = denominator;
  }
 
  int Numerator() const
  {
      return p;
  }
  int Denominator() const
  {
      return q;
  }
 
private:
  int p;
  int q;
};
 
bool operator== (Rational lha, Rational rha)
{
    if ((lha.Numerator() == rha.Numerator()) && (lha.Denominator() == rha.Denominator()))
        return true;
 
    return false;
}
 
Rational operator+ (Rational lha, Rational rha)
{
    if (lha.Denominator() == rha.Denominator())
        return {lha.Numerator() + rha.Numerator(), lha.Denominator()};
 
    int l = std::lcm(lha.Denominator(), rha.Denominator());
    int m = l / lha.Denominator();
    int left_num = lha.Numerator() * m;
    int de = lha.Denominator() * m;
 
    int n = l / rha.Denominator();
    int right_num = rha.Numerator() * n;
 
    return {left_num + right_num, de};
}
 
Rational operator- (Rational lha, Rational rha)
{
    if (lha.Denominator() == rha.Denominator())
        return {lha.Numerator() + rha.Numerator(), lha.Denominator()};
 
    int l = std::lcm(lha.Denominator(), rha.Denominator());
    int m = l / lha.Denominator();
    int left_num = lha.Numerator() * m;
    int de = lha.Denominator() * m;
 
    int n = l / rha.Denominator();
    int right_num = rha.Numerator() * n;
 
    return {left_num - right_num, de};
}