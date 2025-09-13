#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of teams: ";
    cin >> n;

    int** arr = new int*[n];   
    int* size = new int[n];    

 
    for (int i = 0; i < n; i++) {
        cout << "Enter number of players in team " << i + 1 << ": ";
        cin >> size[i];

        arr[i] = new int[size[i]];  

        cout << "Enter scores of team " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nTeam scores and sums:\n";

    for (int i = 0; i < n; i++) {
        int sum = 0;
        cout << "Team " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
        cout << " | Sum = " << sum << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];   
    }
    delete[] arr;          
    delete[] size;         

    return 0;
}
