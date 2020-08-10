#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int getCommandNumber(string& commandInput) {
        string commandNumberString;
        for (int i = commandInput.size() - 1; commandInput[i] != ' '; --i) {
            commandNumberString += commandInput[i];
        } 
        reverse(commandNumberString.begin(), commandNumberString.end());
        int commandNumberInt = stoi(commandNumberString);
        return commandNumberInt;
    }

int main() {
    // Создание списка членов очереди
    vector<bool> numbers(0, false);

    // Создание и ввод количества команд
    int commandsQuontity;
    cin >> commandsQuontity;
    
    // Создание и ввод списка команд
    vector<string> commands(commandsQuontity); 
    string command;    
    for (int i = 0; i <= commandsQuontity; ++i) {
        getline(cin, command);
        commands.push_back(command);
    }
    
    // Перебор списка команд
    for (int i = 0; i < commands.size(); ++i) {        
        // Условие перебора списка команд
        if (commands[i] != "WORRY_COUNT") {
            // Посимвольный перебор строки команды 
            string commandInput = commands[i];           
            string commandWord;
            int commandNumber;
            for (int i = 0; commandInput[i] != ' '; ++i) {
                commandWord += commandInput[i];
            }
            if (commandWord == "COME") {
                commandNumber = getCommandNumber(commandInput);
                numbers.resize(numbers.size() + commandNumber);                
            } else if (commandWord == "WORRY") {
                commandNumber = getCommandNumber(commandInput);
                numbers[commandNumber] = true;
            } else if (commandWord == "QUIET") {
                commandNumber = getCommandNumber(commandInput);
                numbers[commandNumber] = false; 
            }      
        } else {
            int worrySum = 0;
            for (int i = 0; i < numbers.size(); ++i) {
                if (numbers[i]) {
                    worrySum++;
                }            
            }
            cout << worrySum << endl;
        }
    }
    
    return 0;
}