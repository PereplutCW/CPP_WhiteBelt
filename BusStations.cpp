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
            for (auto& item : buses) {                
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
            for (auto& item : buses) {
                if (busName == item.first) {
                    for (auto& item : item.second) {
                        string stop, stopName, busNumbers;
                        stop = item;
                        stopName = "Stop " + item + ": ";
                        for (auto& item : buses) {
                            if (count(begin(item.second), end(item.second), stop) && (item.second[0] != stop)) {
                                busNumbers += item.first + " ";
                            } 
                        }
                        result.push_back(stopName + busNumbers);
                    }
                }
            }
        
        // Описание действий при вводе команды "ALL_BUSES"        
        } else if (commandName == "ALL_BUSES") {
            if (buses.size() == 0) {
                result.push_back("No buses");
            } else {                
                for (auto& item : buses) {                    
                    string busNumber, busStations;
                    busNumber = "Bus " + item.first + ": " + to_string(item.second.size()) + " ";
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