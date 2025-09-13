#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class BookList {
private:
    Node* head;
public:
    BookList() { head = nullptr; }

    void insertFront(string title) {
        Node* n = new Node{title, head};
        head = n;
    }

    void insertEnd(string title) {
        Node* n = new Node{title, nullptr};
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertAfter(string key, string title) {
        Node* temp = head;
        while (temp && temp->data != key) {
            temp = temp->next;
        }
        if (temp) {
            Node* n = new Node{title, temp->next};
            temp->next = n;
        }
    }

    bool search(string title) {
        Node* temp = head;
        while (temp) {
            if (temp->data == title) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    BookList books;

    books.insertEnd("Data Structures");
    books.insertEnd("Operating Systems");
    books.insertEnd("Computer Networks");
    books.insertEnd("Database Systems");

    books.insertFront("Artificial Intelligence");
    books.insertEnd("Machine Learning");
    books.insertAfter("Operating Systems", "Cyber Security");

    cout << "Book List: \n";
    books.display();

    cout << "Searching for 'Database Systems': ";
    cout << (books.search("Database Systems") ? "Found" : "Not Found") << endl;

    return 0;
}
