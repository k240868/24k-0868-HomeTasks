#include <iostream>
using namespace std;

struct Node {
    int compartment;
    Node* prev;
    Node* next;

    Node(int c) {
        compartment = c;
        prev = nullptr;
        next = nullptr;
    }
};

class Train {
private:
    Node* head;
    Node* tail;

public:
    Train() {
        head = nullptr;
        tail = nullptr;
    }

    void addCompartment(int comp) {
        Node* newNode = new Node(comp);
        if (!head) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Compartment " << comp << " added at the end of the train.\n";
    }

    void removeFirstCompartment() {
        if (!head) {
            cout << "Train is empty. No compartment to remove.\n";
            return;
        }
        Node* temp = head;
        cout << "Compartment " << head->compartment << " removed from the train.\n";
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; 
        }
        delete temp;
    }

    void searchCompartment(int comp) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->compartment == comp) {
                cout << "Compartment " << comp << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Compartment " << comp << " not found in the train.\n";
    }

    void displayTrain() {
        if (!head) {
            cout << "Train is empty.\n";
            return;
        }
        cout << "Train compartments (front to end): ";
        Node* temp = head;
        while (temp) {
            cout << temp->compartment << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Train train;
    int choice, comp;

    do {
        cout << "\n--- Railway System Menu ---\n";
        cout << "1. Add Compartment at End\n";
        cout << "2. Remove First Compartment\n";
        cout << "3. Search Compartment\n";
        cout << "4. Display Train\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter compartment number: ";
                cin >> comp;
                train.addCompartment(comp);
                break;
            case 2:
                train.removeFirstCompartment();
                break;
            case 3:
                cout << "Enter compartment number to search: ";
                cin >> comp;
                train.searchCompartment(comp);
                break;
            case 4:
                train.displayTrain();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
