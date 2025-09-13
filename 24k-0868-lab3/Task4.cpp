#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void sortList() {
        if (!head || !head->next) return; 
        for (Node* i = head; i && i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void concatenate(LinkedList& list2) {
        if (!head) { head = list2.head; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = list2.head;
        list2.head = nullptr; 
    }

    void findMiddle() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }

    void removeDuplicates() {
        if (!head) return;
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                Node* dup = curr->next;
                curr->next = curr->next->next;
                delete dup;
            } else {
                curr = curr->next;
            }
        }
    }

    Node* getHead() { return head; }
    void setHead(Node* h) { head = h; }

    static LinkedList mergeSorted(LinkedList& l1, LinkedList& l2) {
        LinkedList result;
        Node dummy(0);
        Node* tail = &dummy;
        Node* a = l1.getHead();
        Node* b = l2.getHead();

        while (a && b) {
            if (a->data < b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = (a) ? a : b;

        result.setHead(dummy.next);
        l1.setHead(nullptr);
        l2.setHead(nullptr);
        return result;
    }
};

int main() {
    LinkedList list1, list2;

    list1.insertAtEnd(5);
    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(2);

    cout << "List 1: ";
    list1.display();

    list1.sortList();
    cout << "Sorted List 1: ";
    list1.display();

    list2.insertAtEnd(4);
    list2.insertAtEnd(6);
    list2.insertAtEnd(7);
    cout << "List 2: ";
    list2.display();

    list1.concatenate(list2);
    cout << "After concatenation: ";
    list1.display();

    list1.findMiddle();

    list1.insertAtEnd(7);
    list1.sortList();
    cout << "Before removing duplicates: ";
    list1.display();
    list1.removeDuplicates();
    cout << "After removing duplicates: ";
    list1.display();

    LinkedList a, b;
    a.insertAtEnd(1);
    a.insertAtEnd(3);
    a.insertAtEnd(5);
    b.insertAtEnd(2);
    b.insertAtEnd(4);
    b.insertAtEnd(6);

    cout << "List A: "; a.display();
    cout << "List B: "; b.display();

    LinkedList merged = LinkedList::mergeSorted(a, b);
    cout << "Merged Sorted List: ";
    merged.display();

    return 0;
}
