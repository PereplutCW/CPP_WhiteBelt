#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;    

int main() {
    vector<int> monthLength = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentMonthNumber = 0;
    int nextMonthNumber = 0;
    vector<vector<string>> currentMonth(monthLength[currentMonthNumber]);
    vector<vector<string>> dumpList;

    // Инициализация и ввод количества команд
    int commandsQuontity;
    cin >> commandsQuontity;

    // Ввод списка команд
    for (int i = 0; i < commandsQuontity; ++i) {
        string commandCode;
        cin >> commandCode;

        // Перебор и анализ вводимых команд
        // Описание действий при введении команды "ADD"
        if (commandCode == "ADD") {
            int commandNumber;
            cin >> commandNumber;
            
            int dayIndex = commandNumber - 1;
            
            string commandName;
            cin >> commandName;

            currentMonth[dayIndex].push_back(commandName);
        // Описание действий при введении команды "DUMP"
        } else if (commandCode == "DUMP") {
            int commandNumber;
            cin >> commandNumber;

            int dayIndex = commandNumber - 1;            

            dumpList.push_back(currentMonth[dayIndex]);
        // Описание действий при введении команды "NEXT"
        } else if (commandCode == "NEXT") {
            nextMonthNumber++;
            if (nextMonthNumber > 11) {
                nextMonthNumber = 0;
            }
            int nextMonthSize = monthLength[nextMonthNumber];
            if (currentMonth.size() > nextMonthSize) {
                int monthSizeDiff = currentMonth.size() - nextMonthSize;
                int currentMonthIndex = currentMonth.size() - 1;
                for (int i = currentMonthIndex; i > currentMonthIndex - monthSizeDiff; --i) {
                    for (auto j : currentMonth[i]) {
                        currentMonth[currentMonthIndex - monthSizeDiff].push_back(j);
                    }
                }
            }
            currentMonthNumber = nextMonthNumber;    
            currentMonth.resize(monthLength[currentMonthNumber]);
        } 
    }
    // Вывод списка дел
    for (int i = 0; i < dumpList.size(); ++i) {
        string resultDump;
        int resultCount = 0;
        for (int j = 0; j < dumpList[i].size(); ++j) {
            resultDump += dumpList[i][j] + ' ';
            resultCount++;
        }
        cout << resultCount << ' ' << resultDump << endl;
    }
           
    return 0;
}