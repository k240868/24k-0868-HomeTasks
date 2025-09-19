#include <iostream>
using namespace std;

void shellSort(int arr[], int size) {

    for (int gap = size / 2; gap > 0; gap /= 2) {
      
        for (int i = gap; i < size; ++i) {
            int key = arr[i];
            int j = i;
      
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "\nOriginal Array: ";
    printArray(arr, size);

    shellSort(arr, size);

    cout << "\nSorted Array using Shell Sort: ";
    printArray(arr, size);

    return 0;
}
