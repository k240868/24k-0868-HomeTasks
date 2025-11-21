#include <iostream>
#include <string>

using namespace std;

const int BUCKETS = 10;

struct Node {
	string data;
	Node* next;
};

Node* hashTable[BUCKETS];

int getHash(string s) {
	int sum = 0;
	for (char c : s) {
		sum += c;
	}
	return sum % BUCKETS;
}

void insert(string s) {
	int index = getHash(s);
	Node* newNode = new Node;
	newNode->data = s;
	newNode->next = hashTable[index];
	hashTable[index] = newNode;
}

void printTable() {
	cout << "Hash Table:" << endl;
	for (int i = 0; i < BUCKETS; i++) {
		cout << "Bucket " << i << ": ";
		Node* current = hashTable[i];
		while (current) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}
}

void search(string s) {
	int index = getHash(s);
	bool found = false;
	Node* current = hashTable[index];
	while (current) {
		if (current->data == s) {
			found = true;
			break;
		}
		current = current->next;
	}
	cout << "Searching '" << s << "': ";
	if (found) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
}

int main() {
	for(int i = 0; i < BUCKETS; i++) {
		hashTable[i] = nullptr;
	}

	insert("apple");
	insert("mango");
	insert("apple");
	insert("grapes");
	insert("peach");
	insert("banana");

	printTable();
	cout << endl;

	search("apple");
	search("orange");

	for(int i = 0; i < BUCKETS; i++) {
		Node* current = hashTable[i];
		while(current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	return 0;
}
