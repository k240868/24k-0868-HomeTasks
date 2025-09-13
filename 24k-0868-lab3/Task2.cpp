#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    Node* next;
    
    Node(string t) {
        title = t;
        next = nullptr;
    }
};

class LibraryCatalog {
private:
    Node* head;
    Node* tail;

public:
    LibraryCatalog() {
        head = nullptr;
        tail = nullptr;
    }

    void addBookTail(string title) {
        Node* newNode = new Node(title);
        if (!head) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Book \"" << title << "\" added to catalog.\n";
    }

    void deleteBookFront() {
        if (!head) {
            cout << "Catalog is empty. No book to delete.\n";
            return;
        }
        Node* temp = head;
        cout << "Book \"" << head->title << "\" deleted from catalog.\n";
        head = head->next;
        if (!head) tail = nullptr; 
        delete temp;
    }

    void searchByTitle(string title) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->title == title) {
                cout << "Book \"" << title << "\" found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book \"" << title << "\" not found in catalog.\n";
    }

    void searchByPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (pos == position) {
                cout << "Book at position " << position << ": " << temp->title << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "No book found at position " << position << ".\n";
    }

    void displayCatalog() {
        if (!head) {
            cout << "Catalog is empty.\n";
            return;
        }
        cout << "Library Catalog:\n";
        Node* temp = head;
        int pos = 1;
        while (temp) {
            cout << pos << ". " << temp->title << "\n";
            temp = temp->next;
            pos++;
        }
    }
};

int main() {
    LibraryCatalog catalog;
    int choice;
    string title;
    int pos;

    do {
        cout << "\n--- Library Catalog Menu ---\n";
        cout << "1. Add Book to Tail\n";
        cout << "2. Delete Book from Front\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Search Book by Position\n";
        cout << "5. Display Catalog\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                catalog.addBookTail(title);
                break;
            case 2:
                catalog.deleteBookFront();
                break;
            case 3:
                cout << "Enter book title to search: ";
                getline(cin, title);
                catalog.searchByTitle(title);
                break;
            case 4:
                cout << "Enter position to search: ";
                cin >> pos;
                catalog.searchByPosition(pos);
                break;
            case 5:
                catalog.displayCatalog();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
