#include <iostream>
using namespace std;

class Box {
    int* volume;

public:
    Box() {
        volume = new int;
        *volume = 0;
    }

    Box(int v) {
        volume = new int;
        *volume = v;
    }

    Box(const Box& b) {
        volume = new int;
        *volume = *(b.volume);
    }

    ~Box() {
        delete volume;
    }

    void setVolume(int v) {
        *volume = v;
    }

    void show() {
        cout << "Volume: " << *volume << endl;
    }
};

int main() {
    Box b1;           
    cout << "b1 -> ";
    b1.show();

    Box b2(30);      
    cout << "b2 -> ";
    b2.show();

    Box b3 = b2;      
    cout << "b3 (copy of b2) -> ";
    b3.show();

    b3.setVolume(60);
    cout << "\nAfter changing b3:\n";
    cout << "b2 -> ";
    b2.show();
    cout << "b3 -> ";
    b3.show();
  
    return 0;
}
