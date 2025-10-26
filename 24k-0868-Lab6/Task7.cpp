#include <iostream>
#include <string>
using namespace std;

class Queue {
    string patrons[100];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool empty() {
        return front == -1 || front > rear;
    }

    bool full() {
        return rear == 99;
    }

    void addPatron(string name) {
        if (full()) {
            cout << "Queue is full. Please wait.\n";
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout << name << " has joined the queue.\n";
    }

    void removePatron() {
        if (empty()) {
            cout << "No patrons to serve.\n";
            return;
        }
        cout << patrons[front] << " has been served and leaves the queue.\n";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }

    void showQueue() {
        if (empty()) {
            cout << "No patrons in queue.\n";
            return;
        }
        cout << "\nCurrent queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << patrons[i] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout << "\n--- Library Queue System ---\n";
        cout << "1. Add Patron\n";
        cout << "2. Serve Patron\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patron name: ";
                cin >> name;
                q.addPatron(name);
                break;
            case 2:
                q.removePatron();
                break;
            case 3:
                q.showQueue();
                break;
            case 4:
                cout << "Closing system.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
