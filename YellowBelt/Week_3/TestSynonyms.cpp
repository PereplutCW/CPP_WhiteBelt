#include "Synonyms.h"
#include "Tests.h"

using namespace std;

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