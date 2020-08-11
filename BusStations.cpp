#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

void PrintResult() {};

int main() {
    map<string, vector<string>> buses;
    vector<string> result;
    string busesForStop;

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
            for (auto item : buses) {                
                int stopQuantity = count(begin(item.second), end(item.second), stopName);
                if (stopQuantity > 0) {
                    busesForStop += item.first + " ";
                } 
            }
            if (busesForStop.size()) {
                result.push_back(busesForStop);
            } else {
                result.push_back("No stop");
            }
            busesForStop.clear();
        // Описание действий при вводе команды "STOPS_FOR_BUS"
        } else if (commandName == "STOPS_FOR_BUS") {
            //
        // Описание действий при вводе команды "ALL_BUSES"        
        } else if (commandName == "ALL_BUSES") {
            if (buses.size() == 0) {
                result.push_back("No buses");
            } else {                
                for (auto item : buses) {                    
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
    for (auto item : result) {
        cout << item << endl;
    }

    return 0;
}