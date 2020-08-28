#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Person {

    public:
    void ChangeFirstName(int year, const string& firstName) {
        firstNameList[year] = firstName;
    }
    void ChangeLastName(int year, const string& lastName) {
        lastNameList[year] = lastName;
    }
    string GetFullName(int year) {
        string currentFirstName, currentLastName;
        currentFirstName = FindNameByYear(year, firstNameList);
        currentLastName = FindNameByYear(year, lastNameList);
        if ((currentFirstName.size() == 0) && (currentLastName.size() == 0)) {
            return "Incognito";
        } else if (currentFirstName.size() == 0) {
            return currentLastName + " with unknown first name";
        } else if (currentLastName.size() == 0) {
            return currentFirstName + " with unknown last name";
        } else {
            return currentFirstName + " " + currentLastName;
        }
    }
    string GetFullNameWithHistory(int year) {
        string currentFirstName, currentLastName;        
        currentFirstName = FindNameByYearWithHistory(year, firstNameList);
        currentLastName = FindNameByYearWithHistory(year, lastNameList);
        if ((currentFirstName.empty()) && (currentLastName.empty())) {
            return "Incognito";
        } else if (currentFirstName.empty()) {
            return currentLastName + " with unknown first name";
        } else if (currentLastName.empty()) {
            return currentFirstName + " with unknown last name";
        } else {
            return currentFirstName + " " + currentLastName;
        }
    }

    private:
    string FindNameByYear(int year, const map<int, string>& nameList) {
        string name;
        for (const auto& item : nameList) {
            if (item.first <= year) {
                name = item.second;
            } else {
                break;
            }
        }
        return name;
    }
    string FindNameByYearWithHistory(int year, const map<int, string>& nameList) {
        string name, names;
        vector<string> nameHistory;
        for (const auto& item : nameList) {
            if (item.first <= year) {
                name = item.second;
                if ((nameHistory.size() == 0) || 
                    (nameHistory[nameHistory.size() - 1] != item.second)) {
                    nameHistory.push_back(item.second);
                }
            } else {
                break;
            }
        }
        // nameHistory.pop_back();
        // reverse(nameHistory.begin(), nameHistory.end());
        if (nameHistory.size() > 0) {
            for (const auto& item : nameHistory) {
                names += item;
            }
            return name + " (" + names + ")";
        } else {
            return name;
        }
    }
    map<int, string> firstNameList;
    map<int, string> lastNameList;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
   }
  
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
  
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
  
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}