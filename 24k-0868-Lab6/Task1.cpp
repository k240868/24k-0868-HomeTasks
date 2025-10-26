#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class CallHistory {
private:
    string names[MAX];
    string numbers[MAX];
    int durations[MAX];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(string name, string number, int duration) {
        if (full()) {
            cout << "Call history is full!\n";
            return;
        }
        topIndex++;
        names[topIndex] = name;
        numbers[topIndex] = number;
        durations[topIndex] = duration;
        cout << "Call added successfully.\n";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "No call history to delete!\n";
            return;
        }
        cout << "Deleting call: " << names[topIndex] << " (" << numbers[topIndex] << ")\n";
        topIndex--;
        display();
    }

    void top() {
        if (empty()) {
            cout << "No recent call.\n";
            return;
        }
        cout << "Most recent call:\n";
        cout << "Name: " << names[topIndex] << "\n";
        cout << "Number: " << numbers[topIndex] << "\n";
        cout << "Duration: " << durations[topIndex] << " mins\n";
    }

    void display() {
        if (empty()) {
            cout << "Call history is empty.\n";
            return;
        }
        cout << "\nCurrent Call History:\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << i + 1 << ". " << names[i] << " | " << numbers[i] << " | " << durations[i] << " mins\n";
        }
        cout << endl;
    }
};

int main() {
    CallHistory history;
    int choice;
    string name, number;
    int duration;

    do {
        cout << "\n--- Call History Menu ---\n";
        cout << "1. Add New Call (push)\n";
        cout << "2. Delete Recent Call (pop)\n";
        cout << "3. Show Most Recent Call (top)\n";
        cout << "4. Check if History is Empty (empty)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter number: ";
                cin >> number;
                cout << "Enter duration (in mins): ";
                cin >> duration;
                history.push(name, number, duration);
                break;

            case 2:
                history.pop();
                break;

            case 3:
                history.top();
                break;

            case 4:
                if (history.empty())
                    cout << "Call history is empty.\n";
                else
                    cout << "Call history is not empty.\n";
                break;

            case 5:
                cout << "Exited\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

