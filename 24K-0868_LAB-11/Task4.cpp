#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 15;

class StudentHashTable {
private:
    int rollNumbers[TABLE_SIZE];
    string studentNames[TABLE_SIZE];

public:
    StudentHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            rollNumbers[i] = -1; 
            studentNames[i] = "";
        }
    }

    int hashFunction(int rollNum) {
        return rollNum % TABLE_SIZE;
    }

    void InsertRecord(int rollNum, string name) {
        int initialIndex = hashFunction(rollNum);
        int index;
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            index = (initialIndex + attempt * attempt) % TABLE_SIZE;

            if (rollNumbers[index] == -1 || rollNumbers[index] == -2) { 
                rollNumbers[index] = rollNum;
                studentNames[index] = name;
                cout << "Record inserted: Roll " << rollNum << ", Name " << name << endl;
                return;
            }
            if (rollNumbers[index] == rollNum) { 
                cout << "Error: Roll number " << rollNum << " already exists." << endl;
                return;
            }
            attempt++;
        }
        cout << "Error: Hash table is full. Could not insert Roll " << rollNum << endl;
    }

    void SearchRecord(int rollNum) {
        int initialIndex = hashFunction(rollNum);
        int index;
        int attempt = 0;

        while (attempt < TABLE_SIZE) {
            index = (initialIndex + attempt * attempt) % TABLE_SIZE;

            if (rollNumbers[index] == rollNum) { 
                cout << "Record found: Roll " << rollNum << ", Name " << studentNames[index] << endl;
                return;
            }
            if (rollNumbers[index] == -1) { 
                cout << "Record not found for Roll " << rollNum << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found for Roll " << rollNum << endl; 
    }

    void DisplayTable() {
        cout << "\n--- Current Hash Table ---" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (rollNumbers[i] != -1 && rollNumbers[i] != -2) { 
                cout << "Roll " << rollNumbers[i] << ", Name " << studentNames[i];
            } else if (rollNumbers[i] == -1) {
                cout << "Empty";
            } else if (rollNumbers[i] == -2) {
                 cout << "Deleted";
            }
            cout << endl;
        }
        cout << "--------------------------\n" << endl;
    }
};

int main() {
    StudentHashTable table;

    table.InsertRecord(101, "Alina");
    table.InsertRecord(205, "Babar");
    table.InsertRecord(300, "Chandan");
    table.InsertRecord(101, "Dawood"); 
    table.InsertRecord(116, "Eeman"); 
    table.InsertRecord(131, "Fiza"); 
    table.InsertRecord(146, "Gotam"); 
    table.InsertRecord(161, "Hamaad"); 
    table.InsertRecord(176, "Iqra"); 
    table.InsertRecord(191, "Javeria");  
    table.InsertRecord(206, "Khizer");  
    table.InsertRecord(221, "Laiba");  
    table.InsertRecord(236, "Moazam"); 
    table.InsertRecord(251, "Nabeel"); 
    table.InsertRecord(266, "Oman"); 
    table.InsertRecord(281, "Pushpa"); 

    table.DisplayTable();

    table.SearchRecord(101);
    table.SearchRecord(300);
    table.SearchRecord(999);
    table.SearchRecord(116);
    table.SearchRecord(281);

    return 0;
}
