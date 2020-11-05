#include <iostream>
#include <sstream>
#include <map>
#include <set>
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

class Person {
    public:
    void ChangeFirstName(int year, const string& firstName) {
        firstNameList[year] = firstName;
    }
    void ChangeLastName(int year, const string& lastName) {
        lastNameList[year] = lastName;
    }
    string GetFullName(int year) {
        string currentFirstName, currentLastName;
        for (const auto& item : lastNameList) {
            if (item.first <= year) {
                currentLastName = item.second;
                for (const auto& item : firstNameList) {
                    if (item.first <= year) {
                        currentFirstName = item.second;
                    }
                }
            }
        }
        for (const auto& item : firstNameList) {
            if (item.first <= year) {
                currentFirstName = item.second;
                for (const auto& item : lastNameList) {
                    if (item.first <= year) {
                        currentLastName = item.second;
                    }
                }
            }
        }        
        if ((currentFirstName.size() == 0) && (currentLastName.size() == 0)) {
            return "Incognito";
        } else if (currentFirstName.size() == 0) {
            return currentLastName + " with unknown first name";
        } else if (currentLastName.size() == 0) {
            return currentFirstName + " with unknown last name";
        } else {
            return currentFirstName + " " + currentLastName;
        }
    }
    private:
    map<int, string> firstNameList;
    map<int, string> lastNameList;
};

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  return 0;
}
