#include <iostream>
using namespace std;

class Node {
	public:
		string name;
		Node* left;
		Node* right;

		Node(string n) {
			name = n;
			left = NULL;
			right = NULL;
		}
};

class TourTree {
	public:
		Node* root;

		TourTree() {
			root = NULL;
		}

		Node* addPackage(Node* root, string name) {
			if (root == NULL) {
				root = new Node(name);
				return root;
			}
			char choice; 
			cout << "Add " << name << " to left or right of " << root->name << "? (l/r): ";
			cin >> choice;
			if (choice == 'l')
				root->left = addPackage(root->left, name);
			else
				root->right = addPackage(root->right, name);
			return root;
		}

		void display(Node* root, int space = 0) {
			if (root == NULL)
			
				return;
			space += 5;
			display(root->right, space);
			cout << endl;
			for (int i = 5; i < space; i++)
				cout << " ";
			cout << root->name << endl;
			display(root->left, space);
		}
};

int main() {
	TourTree tree;
	int n;
	string name;
	cout << "Enter number of tour packages: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Enter package name: ";
		getline(cin, name);
		if (tree.root == NULL)
			tree.root = new Node(name);
		else
			tree.addPackage(tree.root, name);
	}
	cout << "\nTour Package Hierarchy:\n";
	tree.display(tree.root);
	return 0;
}
			
