#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> Q; 
    char choice; 
    int num;    

    do {
        cout << "[A] Push Data" << endl;
        cout << "[B] Pop Data" << endl;
        cout << "[C] Show Front" << endl;
        cout << "[D] Show Back" << endl;
        cout << "[E] Quit" << endl; // 
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter data to push: ";
                cin >> num;
                Q.push(num);
                cout << "Pushed " << num << " onto the queue." << endl;
                break;
            case 'B':
            case 'b':
                if (!Q.empty()) {
                    cout << "Popped " << Q.front() << " from the queue." << endl;
                    Q.pop();
                } else {
                    cout << "Queue is empty. Cannot pop." << endl;
                }
                break;
            case 'C':
            case 'c':
                if (!Q.empty()) {
                    cout << "Front element: " << Q.front() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 'D':
            case 'd':
                if (!Q.empty()) {
                    cout << "Back element: " << Q.back() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
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