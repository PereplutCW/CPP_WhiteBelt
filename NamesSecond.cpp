#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
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
        if (firstNameList.size() == 0) {
            for (const auto& item : lastNameList) {
                if (item.first <= year) {
                    currentLastName = item.second;
                    for (const auto& item : firstNameList) {
                        if (item.first <= year) {
                            currentFirstName = item.second;
                        }
                    }
                }
            }
        } else { 
            for (const auto& item : firstNameList) {
                if (item.first <= year) {
                    currentFirstName = item.second;
                    for (const auto& item : lastNameList) {
                        if (item.first <= year) {
                            currentLastName = item.second;
                        }
                    }
                }
            }
        }
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
    string GetFullNameWithHistory(int year) {}
    private:
    string GetNameList(int year, map<int, string> nameList) {
        vector<string> nameHistory;
        for (const auto& item : nameList) {
            if (item.first <= year) {
                if (count(begin(nameHistory), end(nameHistory), item.second) == 0) {
                    nameHistory.push_back(item.second);
                }
            }
        }
        reverse(nameHistory.begin(), nameHistory.end());
    }
    map<int, string> firstNameList;
    map<int, string> lastNameList;
};

int main() {
    Person person;    
    
    return 0;
}