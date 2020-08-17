#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    map<vector<string>, int> buses;    
    vector<string> result;

    // Инициализация и ввод количества команд
    int requestQuantity;
    cin >> requestQuantity;
    
    // Ввод списка команд
    for (int i = 0; i < requestQuantity; ++i) {
        int stopQuantity;
        cin >> stopQuantity; 

        vector<string> stops;
        string stopName;
        for (int i = 0; i < stopQuantity; ++i) {
            cin >> stopName;
            stops.push_back(stopName);
        }
        
        int busNumber = buses.size() + 1;
        if (buses.count(stops)) {
            for (auto& item : buses) {
                if (stops == item.first) {
                    result.push_back("Already exists for " + to_string(item.second));
                }
            }
        } else {
            buses[stops] = busNumber;
            result.push_back("New bus " + to_string(busNumber));
        }
    }

    // Вывод ответов базы данных   
    for (auto& item : result) {
        cout << item << endl;
    }

    return 0;
}