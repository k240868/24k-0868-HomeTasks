#include <iostream>
using namespace std;

class Exam {
    int* marks;
    int n;

public:
    Exam(int size) {
        n = size;
        marks = new int[n];
        for (int i = 0; i < n; i++)
            marks[i] = 0;   
    }

    ~Exam() {
        delete[] marks;
    }

    void setMark(int i, int m) {
        if (i >= 0 && i < n)
            marks[i] = m;
    }

    void show() {
        cout << "Marks: ";
        for (int i = 0; i < n; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};

int main() {
    Exam e1(3);    
    e1.setMark(0, 50);
    e1.setMark(1, 60);
    e1.setMark(2, 70);

    cout << "e1 -> ";
    e1.show();

    Exam e2 = e1;  

    cout << "e2 (copied from e1) -> ";
    e2.show();

    e2.setMark(1, 99);

    cout << "\nAfter changing e2:\n";
    cout << "e1 -> ";
    e1.show();  
    cout << "e2 -> ";
    e2.show();

    return 0;
}
