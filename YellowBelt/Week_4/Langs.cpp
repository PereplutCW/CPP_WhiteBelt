#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(It range_begin, It range_end) {
    for (auto it = range_begin; it != range_end; ++it) {
        cout << *it << " ";
    }
}

int main() {
    vector<string> langs = {
        "C",
        "C++",        
        "Python",
        "Java",
        "C#"
    };  
    
    int size;
    cin >> size;
    deque<int> d(size);
    while(!d.empty()) {
        d.pop_front();
    }
    cout << "Empty!" << endl;
    

    return 0;
}