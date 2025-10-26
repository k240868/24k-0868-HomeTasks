#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }
    void push(char c) { arr[++topIndex] = c; }
    char pop() { return arr[topIndex--]; }
    char top() { return arr[topIndex]; }
    bool empty() { return topIndex == -1; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = "";
    Stack s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') postfix += s.pop();
            s.pop();
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c) && c != '^')
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.empty()) postfix += s.pop();

    cout << postfix;
    return 0;
}
