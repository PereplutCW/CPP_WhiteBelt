#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int birthDay;
    int birthMonth;
    int birthYear;
};

int main() {
    vector<Student> studentsList;
    string firstName, lastName;
    int birthDay = 0;
    int birthMonth = 0;
    int birthYear = 0;

    int studentsQuantity = 0;
    cin >> studentsQuantity; 

    for (int i = 0; i < studentsQuantity; ++i) {
        cin >> firstName >> lastName >> birthDay >> birthMonth >> birthYear;
        studentsList.push_back(Student{firstName, lastName, birthDay, birthMonth, birthYear});        
    }

    int requestsQuantity = 0;
    string request;
    int studentNumber;
    cin >> requestsQuantity; 

    for (int i = 0; i < requestsQuantity; ++i) {
        cin >> request >> studentNumber;
        --studentNumber;

        if ((request == "name") && (studentNumber >= 0) && (studentNumber < studentsQuantity)) {
            cout << studentsList[studentNumber].firstName << " " << 
            studentsList[studentNumber].lastName << endl;
        } else if ((request == "date") && (studentNumber >= 0) && (studentNumber < studentsQuantity)) {
            cout << studentsList[studentNumber].birthDay << "." << 
            studentsList[studentNumber].birthMonth << "." <<
            studentsList[studentNumber].birthYear << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}