#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

void AddSynonyms(map<string, set<string>>& vocabulary, 
                 const string& word1, const string& word2) {
    vocabulary[word1].insert(word2);
    vocabulary[word2].insert(word1);
}

size_t GetSynonymCount(map<string, set<string>>& vocabulary, const string& word) {
    return vocabulary[word].size();
}

bool AreSynonyms(map<string, set<string>>& vocabulary, 
                 const string& word1, const string& word2) {
    return (vocabulary.count(word1)) && (vocabulary[word1].count(word2));
}

int main() {
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