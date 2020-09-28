#include <iostream>
#include <algorithm>
#include <map>
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
    private:
    map<int, string> firstNameList;
    map<int, string> lastNameList;
};

int main() {
    Person person; 
    
    return 0;
}