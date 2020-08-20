#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Lecture {
        string title;
        int duration;
        string author;
    };

void PrintLecture(const Lecture& lecture) {
    cout << "Title: "<< lecture.title 
         << ", duration: " << lecture.duration 
         << ", author: " << lecture.author << "\n";
}

void PrintCourse(const vector<Lecture>& lectures) {
    for (const Lecture& lecture : lectures) {
        PrintLecture(lecture);
    }
}

int main() {
    Lecture lecture1 = {"Lecture 1", 5400, "Anton"};
    Lecture lecture2 = {"Lecture 2", 3200, "Alexander"};
    Lecture lecture3 = {"Lecture 3", 4500, "Alexey"};
    Lecture lecture4 = {"Lecture 4", 5600, "Anton"};
    Lecture lecture5 = {"Lecture 5", 3500, "Alexander"};

    vector<Lecture> lectures = {lecture1, lecture2, lecture3, lecture4, lecture5};

    PrintCourse(lectures);

    return 0;
}