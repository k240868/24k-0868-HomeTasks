#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;  
    }
}

int bubbleSort(int arr[], int size) {
    int comparisons = 0;
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  
    }
    return comparisons;
}

int insertionSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        comparisons++; 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++; 
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int selectionSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return comparisons;
}

int shellSort(int arr[], int size) {
    int comparisons = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int key = arr[i];
            int j = i;
            comparisons++; 
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
                comparisons++; 
            }
            arr[j] = key;
        }
    }
    return comparisons;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  
    const int SIZE = 20;
    int arr[SIZE];
    generateRandomArray(arr, SIZE);

    cout << "Original Array: ";
    printArray(arr, SIZE);

    int arrBubble[SIZE], arrInsertion[SIZE], arrSelection[SIZE], arrShell[SIZE];
    copy(arr, arr + SIZE, arrBubble);
    copy(arr, arr + SIZE, arrInsertion);
    copy(arr, arr + SIZE, arrSelection);
    copy(arr, arr + SIZE, arrShell);

    int bubbleComparisons = bubbleSort(arrBubble, SIZE);
    cout << "Bubble Sort Result: ";
    printArray(arrBubble, SIZE);
    cout << "Bubble Sort Comparisons: " << bubbleComparisons << endl;

    int insertionComparisons = insertionSort(arrInsertion, SIZE);
    cout << "Insertion Sort Result: ";
    printArray(arrInsertion, SIZE);
    cout << "Insertion Sort Comparisons: " << insertionComparisons << endl;

    int selectionComparisons = selectionSort(arrSelection, SIZE);
    cout << "Selection Sort Result: ";
    printArray(arrSelection, SIZE);
    cout << "Selection Sort Comparisons: " << selectionComparisons << endl;

    int shellComparisons = shellSort(arrShell, SIZE);
    cout << "Shell Sort Result: ";
    printArray(arrShell, SIZE);
    cout << "Shell Sort Comparisons: " << shellComparisons << endl;

    const int NEW_SIZE = 100;
    int arrExpanded[NEW_SIZE];
    generateRandomArray(arrExpanded, NEW_SIZE);

    cout << "\nExpanded Array (100 elements): ";
    printArray(arrExpanded, NEW_SIZE);

    return 0;
}
