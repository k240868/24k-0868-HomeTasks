#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Stack {
    double arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    bool empty() { return topIndex == -1; }
    void push(double n) { arr[++topIndex] = n; }
    double pop() { return arr[topIndex--]; }
};

double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

int main() {
    string exp;
    Stack s;
    cout << "Enter prefix expression: ";
    cin >> exp;
    for (int i = exp.size() - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) s.push(c - '0');
        else {
            double x = s.pop();
            double y = s.pop();
            s.push(calculate(x, y, c));
        }
    }
    cout << "Final evaluated result: " << s.pop();
    return 0;
}
