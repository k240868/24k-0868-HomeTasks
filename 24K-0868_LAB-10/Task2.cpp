#include <iostream>
using namespace std;

void insertHeap(int h[], int &n, int x) {
    h[n] = x;
    int i = n;
    n++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] < h[i]) {
            int t = h[p];
            h[p] = h[i];
            h[i] = t;
            i = p;
        } else break;
    }
}

void removeMax(int h[], int &n) {
    h[0] = h[n - 1];
    n--;
    int i = 0;
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int m = i;
        if (l < n && h[l] > h[m]) m = l;
        if (r < n && h[r] > h[m]) m = r;
        if (m == i) break;
        int t = h[i];
        h[i] = h[m];
        h[m] = t;
        i = m;
    }
}

int main() {
    int h[20];
    int n = 4;

    h[0] = 9;
    h[1] = 7;
    h[2] = 8;
    h[3] = 5;

    insertHeap(h, n, 10);
    removeMax(h, n);

    for (int i = 0; i < n; i++) cout << h[i] << " ";
}
