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
        reverse(nameHistory.begin(), nameHistory.end());
        if (nameHistory.size() > 1) {
            for (int i = 1; i < nameHistory.size(); ++i) {
                names += nameHistory[i] + ", ";
            }
            for (int i = 0; i < 2; ++i) {
                names.pop_back();
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
    
    return 0;
}