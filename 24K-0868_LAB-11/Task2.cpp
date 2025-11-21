#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

class Node {
	public:
		string data;
		Node* next;

		Node(string s) {
			data = s;
			next = nullptr;
		}
};

Node* dictionary[TABLE_SIZE];

int calculateHash(string s) {
	int sum = 0;
	for (char c : s) {
		sum += c;
	}
	return sum % TABLE_SIZE;
}

void Add_Record() {
	string word;
	cout << "Enter word to add: ";
	cin >> word;

	int key = calculateHash(word);

	Node* newNode = new Node(word);
	newNode->next = dictionary[key];
	dictionary[key] = newNode;

	cout << "'" << word << "' added to dictionary." << endl;
}

void Word_Search() {
	string word;
	cout << "Enter word to search: ";
	cin >> word;

	int key = calculateHash(word);
	bool found = false;

	Node* current = dictionary[key];
	while (current) {
		if (current->data == word) {
			found = true;
			break;
		}
		current = current->next;
	}

	if (found) {
		cout << "'" << word << "' found in dictionary." << endl;
	} else {
		cout << "Error: '" << word << "' not found in dictionary." << endl;
	}
}

void Print_Dictionary() {
	cout << "\n--- Dictionary Contents ---" << endl;
	for (int i = 0; i < TABLE_SIZE; i++) {
		Node* current = dictionary[i];
		if (current) {
			cout << "Bucket " << i << ": ";
			while (current) {
				cout << current->data;
				if (current->next) {
					cout << " -> ";
				}
				current = current->next;
			}
			cout << endl;
		}
	}
	cout << "---------------------------\n" << endl;
}

int main() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		dictionary[i] = nullptr;
	}

	int choice;
	do {
		cout << "Dictionary App Menu:" << endl;
		cout << "1. Add Record" << endl;
		cout << "2. Word Search" << endl;
		cout << "3. Print Dictionary" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				Add_Record();
				break;
			case 2:
				Word_Search();
				break;
			case 3:
				Print_Dictionary();
				break;
			case 4:
				cout << "Exiting Dictionary App. Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
		cout << endl;

	} while (choice != 4);

	for (int i = 0; i < TABLE_SIZE; i++) {
		Node* current = dictionary[i];
		while (current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	return 0;
}
