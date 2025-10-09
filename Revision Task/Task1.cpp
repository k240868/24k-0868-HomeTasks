#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        cout << "Array after gap " << gap << " pass: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> bookIDs = {205, 102, 310, 450, 120, 90};

    cout << "Original Book IDs: ";
    for (int i = 0; i < bookIDs.size(); i++) {
        cout << bookIDs[i] << " ";
    }
    cout << endl;

    shellSort(bookIDs);

    cout << "Sorted Book IDs: ";
    for (int i = 0; i < bookIDs.size(); i++) {
        cout << bookIDs[i] << " ";
    }
    cout << endl;

    return 0;
}
