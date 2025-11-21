#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 50;

class EmployeeHashTable {
	private:
		string employeeNames[TABLE_SIZE];

	public:
		EmployeeHashTable() {
			for (int i = 0; i < TABLE_SIZE; i++) {
				employeeNames[i] = "";
			}
		}

		int calculateASCIIsum(string s) {
			int sum = 0;
			for (char c : s) {
				sum += c;
			}
			return sum;
		}

		int h1(string name) {
			return calculateASCIIsum(name) % TABLE_SIZE;
		}

		int h2(string name) {
			return 7 - (calculateASCIIsum(name) % 7);
		}

		void Add_Employee(string name) {
			int initialIndex = h1(name);
			int step = h2(name);
			int index;
			int i = 0;

			while (i < TABLE_SIZE) {
				index = (initialIndex + i * step) % TABLE_SIZE;

				if (employeeNames[index] == "") {
					employeeNames[index] = name;
					cout << "'" << name << "' added to the directory at index " << index << endl;
					return;
				}
				if (employeeNames[index] == name) {
					cout << "Error: '" << name << "' already exists in the directory." << endl;
					return;
				}
				i++;
			}
			cout << "Error: Directory is full. Could not add '" << name << "'" << endl;
		}

		void Search_Employee(string name) {
			int initialIndex = h1(name);
			int step = h2(name);
			int index;
			int i = 0;

			while (i < TABLE_SIZE) {
				index = (initialIndex + i * step) % TABLE_SIZE;

				if (employeeNames[index] == name) {
					cout << "'" << name << "' found in the directory at index " << index << endl;
					return;
				}
				if (employeeNames[index] == "") {
					cout << "Employee not found in the directory." << endl;
					return;
				}
				i++;
			}
			cout << "Employee not found in the directory." << endl;
		}

		void Display_Table() {
			cout << "\n--- Employee Directory Contents ---" << endl;
			for (int i = 0; i < TABLE_SIZE; i++) {
				if (employeeNames[i] != "") {
					cout << "Index " << i << ": " << employeeNames[i] << endl;
				}
			}
			cout << "-----------------------------------\n" << endl;
		}
};

int main() {
	EmployeeHashTable empTable;

	empTable.Add_Employee("Fatima");
	empTable.Add_Employee("Ahmed");
	empTable.Add_Employee("Zainab");
	empTable.Add_Employee("Ali");
	empTable.Add_Employee("Ayesha");
	empTable.Add_Employee("Khan");
	empTable.Add_Employee("Imran");
	empTable.Add_Employee("Sana");
	empTable.Add_Employee("Usman");
	empTable.Add_Employee("Maria");

	empTable.Display_Table();

	empTable.Search_Employee("Fatima");
	empTable.Search_Employee("Ali");
	empTable.Search_Employee("Sadaf");
	empTable.Search_Employee("Imran");

	return 0;
}
