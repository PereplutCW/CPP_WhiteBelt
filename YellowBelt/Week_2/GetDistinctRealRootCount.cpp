#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>

using namespace std;

/*

set<double> SolveQuadraticEquation(double a, double b, double c) {
  set<double> quadratic_roots;
  if ((a != 0) && (b != 0) && (c != 0)) {
    double d = (b * b) - (4 * a * c);
    if (d > 0) {
      double x1 = (-b + sqrt(d)) / (2 * a);
      double x2 = (-b - sqrt(d)) / (2 * a);
      quadratic_roots.insert(x1, x2);
    } else if (d == 0) {
      double x = -b / (2 * a);
      quadratic_roots.insert(x);
    }
  } else if ((a != 0) && (b == 0) && (c == 0)) {
      double x = 0;
      quadratic_roots.insert(x);
  } else if (((a > 0) && (b == 0) && (c < 0)) || ((a< 0) && (b == 0) && (c > 0))) {
      double x1 = sqrt(-c / a);
      double x2 = -sqrt(-c / a);
      quadratic_roots.insert(x1, x2);
  } else if ((a != 0) && (b != 0) && (c == 0)) {
      double x1 = 0;
      double x2 = -(b / a);
      quadratic_roots.insert(x1, x2);
  }
  return quadratic_roots;
}

double SolveLinearEquation(double b, double c) {
  if (b != 0) {
    return -c / b;
  }
}

int GetDistinctRealRootCount(double a, double b, double c) {
  set<double> roots;
  int root_count = 0;
  if (a != 0) {
    roots = SolveQuadraticEquation(a, b, c);
  } else {
    roots.insert(SolveLinearEquation(b, c));
  }
  return root_count = roots.size();
}

*/

int GetDistinctRealRootCount(double a, double b, double c) {}

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

void TestRootCount() {
  mt19937 gen;
  uniform_real_distribution<> unif(-10, 10);

  for (auto i = 0; i < 100; i++) {
    const auto a = unif(gen);
    const auto b = unif(gen);
    const auto c = unif(gen);

    const auto count = GetDistinctRealRootCount(a, b, c);
 
    Assert(count >= 0 && count <= 2, 
           "Quadratic equation has only 0, 1 or 2 real roots.");
  }
}

void TestOneRoot() {
  mt19937 gen;
  uniform_real_distribution<> unif(-10, 10);

  for (auto i = 0; i < 100; i++) {
    const auto x1 = unif(gen);

    const auto p = x1 + x1;
    const auto q = x1 * x1;

    const auto count = GetDistinctRealRootCount(1, p, q);
    stringstream description;
    description << showpos << "x^2" << p << "x" << q << 
                " = 0 has 1 real root.";
    AssertEqual(count, 1, description.str());
  }
}

void TestNoRoots() {
  AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0,
              "x^2+1 = 0 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(1, 3, 4), 0, 
              "x^2+3x+4 = 0 has 0 real roots.");
  AssertEqual(GetDistinctRealRootCount(1, -2, 10), 0, 
              "x^2-2x+10 = 0 has 0 real roots.");
}

void TestLinearEquation() {
	AssertEqual(GetDistinctRealRootCount(0, 2, 1), 1,
		"2x+1 = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, -1, 0), 1,
		"-x = 0 has 1 real root.");
	AssertEqual(GetDistinctRealRootCount(0, 120, -10), 1,
		"120x - 10 = 0 has 1 real root.");
}

void TestConstant() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0,
		"c = 0, where c = 1 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0,
		"c = 0, where c = -10 has 0 real roots.");
	AssertEqual(GetDistinctRealRootCount(0, 0, 189238910), 0,
		"c = 0, where c = 189238910 has 0 real roots.");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestRootCount, "TestRootCount");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestNoRoots, "TestNoRoots");
  runner.RunTest(TestLinearEquation, "TestLinearEquation");
  runner.RunTest(TestConstant, "TestConstant");

  return 0;
}
