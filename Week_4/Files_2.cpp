#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    
    ofstream output("output.txt");
    if (input) {
        while (getline(input, line)) {
            output << line << endl;
        }
    }
        
    return 0;
}