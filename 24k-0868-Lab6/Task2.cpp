#include <iostream>
#include <cmath>   
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(int value) {
        if (full()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (empty()) {
            cout << "Stack underflow!\n";
            return 0;
        }
        return arr[topIndex--];
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty!\n";
            return 0;
        }
        return arr[topIndex];
    }
};

int main() {
    Stack s;
    string exp;
    cout << "Enter a postfix expression (e.g., 23*54*+9-): ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            s.push(ch - '0'); 
        } 
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default: 
                    cout << "Invalid operator: " << ch << endl;
                    return 0;
            }
            s.push(result);
        }
    }

    if (!s.empty()) {
        cout << "Final evaluated result: " << s.top() << endl;
    } else {
        cout << "Invalid expression!" << endl;
    }

    return 0;
}
