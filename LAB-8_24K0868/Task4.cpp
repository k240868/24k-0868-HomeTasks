#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int val) {
			data = val;
			left = nullptr;
			right = nullptr;
		}
};

void printPreOrder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int findSubtreeSum(Node* root, int target, bool& found) {
	if (root == nullptr) {
		return 0;
	}

	int leftSum = findSubtreeSum(root->left, target, found);
	int rightSum = findSubtreeSum(root->right, target, found);

	int currentSubtreeSum = root->data + leftSum + rightSum;

	if (!found && currentSubtreeSum == target) {
		found = true;
		cout << "Subtree with sum " << target << " found!" << endl;
		cout << "Subtree Nodes (Pre-order): ";
		printPreOrder(root);
		cout << endl;
	}

	return currentSubtreeSum;
}

int main() {
	Node* root = new Node(100);
	root->left = new Node(50);
	root->right = new Node(60);
	root->left->left = new Node(25);
	root->left->right = new Node(30);
	root->right->left = new Node(5);

	cout << "--- Warehouse Inventory Check ---" << endl;

	int target1 = 105;
	bool found1 = false;

	cout << "\nSearching for target sum: " << target1 << endl;
	findSubtreeSum(root, target1, found1);
	if (!found1) {
		cout << "No subtree found with sum " << target1 << endl;
	}

	int target2 = 42;
	bool found2 = false;

	cout << "\nSearching for target sum: " << target2 << endl;
	findSubtreeSum(root, target2, found2);
	if (!found2) {
		cout << "No subtree found with sum " << target2 << endl;
	}

	return 0;
}
