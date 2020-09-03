#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
        
    return 0;
}