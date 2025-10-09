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
    vector<int> luggageWeights = {32, 25, 40, 12, 18, 50, 28};

    cout << "Original Luggage Weights: ";
    for (int i = 0; i < luggageWeights.size(); i++) {
        cout << luggageWeights[i] << " ";
    }
    cout << endl;

    shellSort(luggageWeights);

    cout << "Sorted Luggage Weights: ";
    for (int i = 0; i < luggageWeights.size(); i++) {
        cout << luggageWeights[i] << " ";
    }
    cout << endl;

    return 0;
}
