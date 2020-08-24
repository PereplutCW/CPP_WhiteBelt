#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

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
            vocabulary[word1].insert(word2);
            vocabulary[word2].insert(word1);
        } else if(commandName == "COUNT") {
            string word;
            cin >> word;
            cout << vocabulary[word].size() << endl;
        } else if (commandName == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (((vocabulary.count(word1)) && (vocabulary[word1].count(word2)))) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        
    }

    return 0;
}