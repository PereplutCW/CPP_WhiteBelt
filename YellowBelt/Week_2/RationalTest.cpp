#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// Реализация класса Rational

int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            p = 0;
            q = 1;
        }
        const int gcd = GCD(numerator, denominator);        
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        if ((numerator > 0) && (denominator > 0)) {
            p = numerator;
            q = denominator;
        } else if ((numerator < 0) && (denominator < 0)) {
            p = abs(numerator);
            q = abs(denominator);
        } else if (((numerator < 0) && (denominator > 0)) || 
                   ((numerator > 0) && (denominator < 0))) {
            p = -abs(numerator);
            q = abs(denominator);
        } 
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;    
};

// Переопределение операторов +, -, *, /, ==, <, >>, << для класса Rational

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && 
        (lhs.Denominator() == rhs.Denominator())) {
        return true;
    } else {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
    } else {
        return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
               lhs.Denominator() * rhs.Denominator()};
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    const auto lhsNum = lhs.Numerator() * rhs.Denominator();
    const auto rhsNum = rhs.Numerator() * lhs.Denominator();
    return lhsNum < rhsNum;
}
 
istream& operator>>(istream& stream, Rational& rational) {
    int numerator, denominator;
    char div;
    stream >> numerator >> div >> denominator;
    if (stream && div == '/') {
        rational = Rational(numerator, denominator);
    } 
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

// Реализация набора юнит-тестов для класса Rational

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты

  Rational r = {5, 10};
  cout << r << endl;

  return 0;
}
