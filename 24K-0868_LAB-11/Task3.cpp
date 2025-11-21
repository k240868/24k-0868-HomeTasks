#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

class Hash {
	private:
		int arr[TABLE_SIZE];
		int currentSize;

	public:
		Hash() {
			for (int i = 0; i < TABLE_SIZE; i++) {
				arr[i] = -1;
			}
			currentSize = 0;
		}

		int hashFunction(int key) {
			return key % TABLE_SIZE;
		}

		void insert(int value) {
			if (currentSize == TABLE_SIZE) {
				cout << "Hash table is full. Cannot insert " << value << endl;
				return;
			}

			int index = hashFunction(value);

			while (arr[index] != -1) {
				index = (index + 1) % TABLE_SIZE;
			}
			arr[index] = value;
			currentSize++;
		}

		void remove(int value) {
			if (currentSize == 0) {
				cout << "Hash table is empty. Cannot remove " << value << endl;
				return;
			}

			int index = hashFunction(value);
			int originalIndex = index;
			bool found = false;

			while (arr[index] != -1) {
				if (arr[index] == value) {
					arr[index] = -2;
					currentSize--;
					found = true;
					break;
				}
				index = (index + 1) % TABLE_SIZE;
				if (index == originalIndex) {
					break;
				}
			}

			if (found) {
				cout << "Remove " << value << endl;
			} else {
				cout << value << " not found for removal." << endl;
			}
		}

		void search(int value) {
			int index = hashFunction(value);
			int originalIndex = index;
			bool found = false;

			while (arr[index] != -1) {
				if (arr[index] == value) {
					found = true;
					break;
				}
				index = (index + 1) % TABLE_SIZE;
				if (index == originalIndex) {
					break;
				}
			}

			if (found) {
				cout << value << " found" << endl;
			} else {
				cout << value << " not found" << endl;
			}
		}

		void display() {
			for (int i = 0; i < TABLE_SIZE; i++) {
				if (arr[i] != -1 && arr[i] != -2) {
					cout << arr[i] << " ";
				}
			}
			cout << endl;
		}
};

int main() {
	Hash h;

	h.insert(1);
	h.insert(3);
	h.insert(4);
	h.insert(5);
	h.insert(7);
	h.display();

	h.remove(4);
	h.display();

	h.search(5);
	h.search(6);

	return 0;
}
