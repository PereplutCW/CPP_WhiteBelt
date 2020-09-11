#include <iostream>
#include <string>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {        
        throw runtime_error(left + " != " + right);
    } 
}

int main() {
    
    return 0;
}
