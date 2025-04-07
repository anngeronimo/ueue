#include <iostream>
#include <stack>
using namespace std;

int number;          
int x;              
stack<int> myStack;

int main() {
    for (x = 1; x <= 5; x++) {
        cout << "Enter an integer: ";
        cin >> number; 
        myStack.push(number); 
    }
    cout << "The integers are: " << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << endl; 
        myStack.pop(); 
    }
    return 0; 
}