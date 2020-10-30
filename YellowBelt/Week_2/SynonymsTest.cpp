#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cassert>

using namespace std;

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
    return (vocabulary.count(word1)) && (vocabulary[word1].count(word2));
}

void TestAddSynonyms() {
    {
        Vocabulary empty;
        AddSynonyms(empty, "a", "b");
        const Vocabulary expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        assert(empty == expected);
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
        assert(vocabulary == expected);
    }
    cout << "TestAddSynonyms OK!" << endl;
}

void TestAll() {
    TestAddSynonyms();
}

int main() {
    // TestAll();
    // return 0;

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