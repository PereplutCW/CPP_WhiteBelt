#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Person {

    public:
    Person(const string& firstName, const string& lastName, int year) {
        birthYear = year;
        firstNameList[year] = firstName;
        lastNameList[year] = lastName;
    }
    void ChangeFirstName(int year, const string& firstName) {
        if (year >= birthYear) {
            firstNameList[year] = firstName;
        }        
    }
    void ChangeLastName(int year, const string& lastName) {
        if (year >= birthYear) {
            lastNameList[year] = lastName;
        }        
    }
    string GetFullName(int year) const {
        if (year < birthYear) {
            return "No person";
        } else {
            string currentFirstName, currentLastName, fullName;
            currentFirstName = FindNameByYear(year, firstNameList);
            currentLastName = FindNameByYear(year, lastNameList);
            fullName = SetFullName(currentFirstName, currentLastName);
            return fullName;
        }
    }
    string GetFullNameWithHistory(int year) const {
        if (year < birthYear) {
            return "No person";
        } else {
            string currentFirstName, currentLastName, fullName;        
            currentFirstName = FindNameByYearWithHistory(year, firstNameList);
            currentLastName = FindNameByYearWithHistory(year, lastNameList);
            fullName = SetFullName(currentFirstName, currentLastName);
            return fullName;
        }        
    }

    private:
    string FindNameByYear(int year, const map<int, string>& nameList) const {
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
    string FindNameByYearWithHistory(int year, const map<int, string>& nameList) const {
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
    string SetFullName(const string& firstName, const string& lastName) const {
        if ((firstName.size() == 0) && (lastName.size() == 0)) {
            return "Incognito";
        } else if (firstName.size() == 0) {
            return lastName + " with unknown first name";
        } else if (lastName.size() == 0) {
            return firstName + " with unknown last name";
        } else {
            return firstName + " " + lastName;
        }
    }
    int birthYear;
    map<int, string> firstNameList;
    map<int, string> lastNameList;
};

int main() {
        
    return 0;
}