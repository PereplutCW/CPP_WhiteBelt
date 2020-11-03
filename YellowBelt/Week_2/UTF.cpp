#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <exception>

using namespace std;

// Переопределение оператора << для типа set<T>

template <typename T>
ostream& operator<<(ostream& os, const set<T> s) {
    os << "{";
    bool first = true;
    for (const auto& v : s) {
        if (!first) {
            os << " ,";
        }
        first = false;
        os << v;
    }
    return os << "}";
    
}

// Переопределение оператора << для типа map<K, V>

template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V> m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << " ,";
        }
        first = false;
        os << kv.first << " : " << kv.second;
    }
    return os << "}";
}

// Определение и реализация функций AssertEqual и Assert для замены assert 
// в юнит-тестах

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u <<
              " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

// Определение и реализация юнит-тестов

void TestSomthing() {}

// Определение и реализация класса TestRunner для вызова любого юнит-теста

class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK!" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << ": " << e.what() << endl;
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

void TestAll() {
    TestRunner tr;
    // tr.RunTest(test_name, "test_name");
}

int main() {
    return 0;
}