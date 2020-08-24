#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, vector<string>> busesRoutes;
    map<int, string> busesNumbers;
    map<int, vector<string>> busesStations;
    int busesCounter = 0;
    vector<string> result;    

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
            busesCounter++;
            string busNumber;
            cin >> busNumber;
            int busStationsNumber;
            cin >> busStationsNumber;
            vector<string> busStations(busStationsNumber);
            for (string& busStation : busStations) {
                cin >> busStation;
            }            
            busesNumbers[busesCounter] = busNumber;
            busesStations[busesCounter] = busStations;
            busesRoutes[busNumber] = busStations;

        // Описание действий при вводе команды "BUSES_FOR_STOP" 
        } else if (commandName == "BUSES_FOR_STOP") {
            string stopName;
            cin >> stopName; 
            string resultString;   
            for (const auto& item : busesStations) {  
                if (count(begin(item.second), end(item.second), stopName)) {
                    int busCounter = item.first;
                    for (const auto& item : busesNumbers) {
                        if (item.first == busCounter) {
                            resultString += item.second + " ";
                        }
                    }
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
            if ((busesRoutes.size() == 0) || (busesRoutes.count(busName)) == 0) {
                result.push_back("No bus");
            } else {
                for (const auto& item : busesRoutes) {
                    if (busName == item.first) {                        
                        for (auto& item : item.second) {                            
                            string stop, stopName, busNumbers;
                            int busCounter = 0;
                            int counter = 0;
                            stop = item;
                            stopName = "Stop " + stop + ": ";                            
                            for (const auto& item : busesStations) {
                                if (count(begin(item.second), end(item.second), stop)) {
                                    busCounter = item.first;
                                    for (const auto& item : busesNumbers) {
                                        if ((item.first == busCounter) && 
                                        (item.second != busName)) {
                                            busNumbers += item.second + " ";
                                            counter++;
                                        }
                                    }
                                }
                            }
                            if (counter == 0) {
                                busNumbers = "no interchange";
                            }
                            result.push_back(stopName + busNumbers);                            
                        }
                    }
                }
            }
        // Описание действий при вводе команды "ALL_BUSES"        
        } else if (commandName == "ALL_BUSES") {
            if (busesRoutes.size() == 0) {
                result.push_back("No buses");
            } else {                
                for (const auto& item : busesRoutes) {                    
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