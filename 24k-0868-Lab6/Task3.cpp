#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string url) {
        data = url;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    void addFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }
    void removeFront() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void display() {
        if (head == NULL) {
            cout << "Browsing history is empty.\n";
            return;
        }
        cout << "Current Browsing History (Most recent first):\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    string currentPage() {
        if (head == NULL) return "No page";
        return head->data;
    }
};

class Stack {
private:
    string arr[100];
    int topIndex;
public:
    Stack() {
        topIndex = -1;
    }
    bool empty() {
        return topIndex == -1;
    }
    void push(string url) {
        if (topIndex == 99) return;
        arr[++topIndex] = url;
    }
    string pop() {
        if (empty()) return "";
        return arr[topIndex--];
    }
    string top() {
        if (empty()) return "No page";
        return arr[topIndex];
    }
};

int main() {
    LinkedList history;
    Stack backStack;
    string sites[5] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        history.addFront(sites[i]);
        backStack.push(sites[i]);
    }
    cout << "After visiting 5 websites:\n";
    history.display();
    cout << "Current page: " << history.currentPage() << endl << endl;
    cout << "User clicks back twice...\n";
    backStack.pop();
    history.removeFront();
    backStack.pop();
    history.removeFront();
    cout << "\nAfter going back twice:\n";
    history.display();
    cout << "Current page: " << history.currentPage() << endl;
    return 0;
}
