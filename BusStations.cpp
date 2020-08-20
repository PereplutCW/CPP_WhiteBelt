#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, vector<string>> buses;
    map<vector<string>, string> reversedBuses;
    vector<string> result;
    string resultString;

    // Инициализация и ввод количества команд
    int requestQuantity;
    cin >> requestQuantity;
    
    // Ввод списка команд
    for (int i = 0; i < requestQuantity; ++i) {
        string commandName;
        cin >> commandName;  

        // Перебор и анализ вводимых команд

        // Описание действий при вводе команды "NEW_BUS"
        if (commandName == "NEW_BUS") {
            string busNumber;
            cin >> busNumber;
            int busStationsNumber;
            cin >> busStationsNumber;
            vector<string> busStations(busStationsNumber);
            for (string& busStation : busStations) {
                cin >> busStation;
            }
            buses[busNumber] = busStations;

        // Описание действий при вводе команды "BUSES_FOR_STOP" 
        } else if (commandName == "BUSES_FOR_STOP") {
            string stopName;
            cin >> stopName;    
            for (const auto& item : buses) {                
                int stopQuantity = count(begin(item.second), end(item.second), stopName);
                if (stopQuantity > 0) {
                    resultString += item.first + " ";
                } 
            }
            if (resultString.size()) {
                result.push_back(resultString);
            } else {
                result.push_back("No stop");
            }
            resultString.clear();

        // Описание действий при вводе команды "STOPS_FOR_BUS"
        } else if (commandName == "STOPS_FOR_BUS") {
            string busName;
            cin >> busName;
            if ((buses.size() == 0) || (buses.count(busName)) == 0) {
                result.push_back("No bus");
            } else {
                for (const auto& item : buses) {
                    if (busName == item.first) {
                        for (auto& item : item.second) {
                            string stop, stopName, busNumbers;
                            int busCount = 0;
                            stop = item;
                            stopName = "Stop " + stop + ": ";                            
                            for (const auto& item : buses) {                                
                                if ((item.first != busName) && 
                                    (count(begin(item.second), end(item.second), stop))) {
                                        busNumbers += item.first + " ";
                                        busCount++;
                                } 
                            }
                            if (busCount == 0) {
                                busNumbers = "no interchange";
                            }
                            result.push_back(stopName + busNumbers);                            
                        }
                    }
                }
            }
        // Описание действий при вводе команды "ALL_BUSES"        
        } else if (commandName == "ALL_BUSES") {
            if (buses.size() == 0) {
                result.push_back("No buses");
            } else {                
                for (const auto& item : buses) {                    
                    string busNumber, busStations;
                    busNumber = "Bus " + item.first + ": ";
                    for (int i = 0; i < item.second.size(); ++i) {
                        busStations += item.second[i] + " ";
                    }
                    result.push_back(busNumber + busStations);
                }
            }
        }
    }

    // Вывод ответов базы данных   
    for (auto& item : result) {
        cout << item << endl;
    }

    return 0;
}

/*
9
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
STOPS_FOR_BUS 950
BUSES_FOR_STOP Marushkino
BUSES_FOR_STOP Vnukovo
BUSES_FOR_STOP Solntsevo

Your output:
Stop Vnukovo: 32 32K 950 
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950 
Stop Kokoshkino: no interchange
Stop Marushkino: 32 32K 
Stop Vnukovo: 272 32 32K 
Stop Peredelkino: 32K 
Stop Solntsevo: 32K 
Stop Troparyovo: 272 
32 32K 950 
272 32 32K 950 
32K 950 

Correct output:
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Stop Kokoshkino: no interchange
Stop Marushkino: 32 32K
Stop Vnukovo: 32 32K 272
Stop Peredelkino: 32K
Stop Solntsevo: 32K
Stop Troparyovo: 272
32 32K 950
32 32K 950 272
32K 950
*/