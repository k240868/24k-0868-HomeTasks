#include <iostream>
using namespace std;

void insertHeap(int h[], int &n, int x) {
    h[n] = x;
    int i = n;
    n++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] > h[i]) {
            int t = h[p];
            h[p] = h[i];
            h[i] = t;
            i = p;
        } else break;
    }
}

int main() {
    int h[20];
    int n = 5;

    h[0] = 1;
    h[1] = 3;
    h[2] = 4;
    h[3] = 5;
    h[4] = 6;

    insertHeap(h, n, 2);

    for (int i = 0; i < n; i++) cout << h[i] << " ";
}

