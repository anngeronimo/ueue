#include <iostream>
#include <queue>
using namespace std;

int number;          
int x; 
queue<int> myQueue;           

int main() {
    for (x = 1; x <= 5; x++) {
        cout << "Enter an integer: ";
        cin >> number; 
        myQueue.push(number); 
    }
    cout << "The integers are: " << endl;
    while (!myQueue.empty()) {
        cout << myQueue.front() << endl; 
        myQueue.pop(); 
    }
    return 0; 
}