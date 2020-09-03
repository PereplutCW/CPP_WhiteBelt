#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int rows = 0;
    int columns = 0;
    int value = 0;

    if (input) {   
        input >> rows;
        input.ignore(1);
        input >> columns;
        input.ignore(1);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                input >> value;
                input.ignore(1);
                cout << setw(10) << value;
                if (j != (columns - 1)) {
                    cout << ' ';
                } 
            }
            if (i != (rows - 1)) {
                cout << endl;
            }
        }
    }
    
    
        
    return 0;
}