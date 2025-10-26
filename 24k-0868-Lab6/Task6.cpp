#include <iostream>
#include <string>
using namespace std;

class Queue {
    string items[100];
    int qty[100];
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

    void enqueue(string order, int q) {
        if (full()) {
            cout << "Order queue is full, cannot take more orders.\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = order;
        qty[rear] = q;
        cout << "Order added: " << order << " (x" << q << ")\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "No orders to process.\n";
            return;
        }
        cout << "Processing order: " << items[front] << " (x" << qty[front] << ")\n";
        front++;
    }

    void displayProcessed() {
        if (front == -1) {
            cout << "No orders available.\n";
            return;
        }
        cout << "\nProcessed Orders:\n";
        for (int i = 0; i <= rear; i++) {
            cout << i + 1 << ". " << items[i] << " (x" << qty[i] << ")\n";
        }
    }
};

int main() {
    Queue orders;
    orders.enqueue("Burger", 2);
    orders.enqueue("Pizza", 1);
    orders.enqueue("Pasta", 3);
    orders.enqueue("Fries", 2);
    orders.enqueue("Cola", 4);

    cout << "\n--- Processing Orders ---\n";
    orders.dequeue();
    orders.dequeue();

    orders.displayProcessed();

    return 0;
}
