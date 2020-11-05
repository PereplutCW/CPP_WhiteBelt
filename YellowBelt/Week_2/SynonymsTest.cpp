#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <exception>

using namespace std;

// Создание типа-синонима Vocabulary для map<string, set<string>>

using Vocabulary = map<string, set<string>>;

void AddSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2) {
    vocabulary[word1].insert(word2);
    vocabulary[word2].insert(word1);
}

size_t GetSynonymCount(Vocabulary& vocabulary, const string& word) {
    return vocabulary[word].size();
}

bool AreSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2) {
    return vocabulary[word1].count(word2) == 0;
}

// Переопределение оператора << для типа set<T>

template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& v : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << v;
    }
    return os << "}";
}

// Переопределение оператора << для типа map<K, V>

template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
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
        os << "Assertion failed: " << t << "!=" << u <<
        " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

// Определение и реализация юнит-теста для функции AddSynonyms

void TestAddSynonyms() {
    {
        Vocabulary empty;
        AddSynonyms(empty, "a", "b");
        const Vocabulary expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };
        AddSynonyms(vocabulary, "a", "c");
        Vocabulary expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}}
        };
        AssertEqual(vocabulary, expected, "Add to vocabulary");
    }
}

// Определение и реализация юнит-теста для функции TestCount

void TestCount() {
    {
        Vocabulary empty;
        AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        AssertEqual(GetSynonymCount(vocabulary, "a"), 2u, "count for a");
        AssertEqual(GetSynonymCount(vocabulary, "b"), 1u, "count for b");
        AssertEqual(GetSynonymCount(vocabulary, "z"), 0u, "count for z");
    }
}

// Определение и реализация юнит-теста для функции TestAreSynonyms

void TestAreSynonyms() {
    {
        Vocabulary empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        Assert(AreSynonyms(vocabulary, "a", "b"), "vocabulary a b");
        Assert(AreSynonyms(vocabulary, "b", "a"), "vocabulary b a");
        Assert(AreSynonyms(vocabulary, "a", "c"), "vocabulary a c");
        Assert(AreSynonyms(vocabulary, "c", "a"), "vocabulary c a");
        // Assert(AreSynonyms(vocabulary, "b", "c"), "vocabulary b c");
    }
}

class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << ": OK!" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << ": " << e.what() << endl;
        }
    }
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            exit(1);
        }
    }
private:
    int fail_count = 0;
};

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
}

int main() {
    TestAll();

    map<string, set<string>> vocabulary;

    // Инициализация и ввод количества команд
    int requestQuantity;
    cin >> requestQuantity;
    
    // Ввод списка команд
    for (int i = 0; i < requestQuantity; ++i) {
        string commandName;
        cin >> commandName;  

        // Перебор и анализ вводимых команд
        if (commandName == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            AddSynonyms(vocabulary, word1, word2);
        } else if(commandName == "COUNT") {
            string word;
            cin >> word;
            cout << GetSynonymCount(vocabulary, word) << endl;
        } else if (commandName == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (AreSynonyms(vocabulary, word1, word2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        
    }

    return 0;
}