#include <iostream>
#include <set> 

using namespace std;

enum class RequestType {
    ADD,
    REMOVE,
    NEGATE
};

void ProcessRequest(set<int>& numbers, RequestType request_type, int request_data) {
    switch (request_type) {
        case RequestType::ADD:
            numbers.insert(request_data);
            break;
        case RequestType::REMOVE:
            numbers.erase(request_data);
            break;
        case RequestType::NEGATE: {
            bool contains = (numbers.count(request_data) == 1);
            if (contains) {
                numbers.erase(request_data);
                numbers.insert(-request_data);
            }
            break;
        }
        default:
            cout << "Unknown request" << endl;

    }
}

int main() {
    set<int> numbers;

    ProcessRequest(numbers, RequestType::ADD, 8);
    ProcessRequest(numbers, RequestType::ADD, 16);
    ProcessRequest(numbers, RequestType::ADD, 32);
    ProcessRequest(numbers, RequestType::REMOVE, 8);
    ProcessRequest(numbers, RequestType::NEGATE, 16);

    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

