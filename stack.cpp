#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> A; 
    char choice; 
    int num;   

    do {
        cout << "[A] Push Data" << endl;
        cout << "[B] Pop Data" << endl;
        cout << "[C] Show Top" << endl;
        cout << "[D] Show Size" << endl;
        cout << "[E] Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter data to push: ";
                cin >> num;
                A.push(num);
                cout << "Pushed data: " << num << endl;
                break;
            case 'B':
            case 'b':
                if (!A.empty()) {
                    cout << "Popped data: " << A.top() << endl;
                    A.pop();
                } else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 'C':
            case 'c':
                if (!A.empty()) {
                    cout << "Top element: " << A.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 'D':
            case 'd':
                cout << "Size of stack: " << A.size() << endl;
                break;
            case 'E':
            case 'e':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'E' && choice != 'e'); 
    return 0; 
}