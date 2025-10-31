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

bool isFullBinaryTree(Node* root) {
	if (root == nullptr) {
		return true;
	}

	if (root->left == nullptr && root->right == nullptr) {
		return true;
	}

	if (root->left != nullptr && root->right != nullptr) {
		return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
	}

	return false;
}

int main() {
	cout << "--- Game Level Analysis ---" << endl;

	Node* levelRoot1 = new Node(1);
	levelRoot1->left = new Node(2);
	levelRoot1->right = new Node(3);
	levelRoot1->left->left = new Node(4);
	levelRoot1->left->right = new Node(5);

	cout << "\nChecking Tree 1..." << endl;
	if (isFullBinaryTree(levelRoot1)) {
		cout << "Result: This tree IS a full binary tree." << endl;
	} else {
		cout << "Result: This tree is NOT a full binary tree." << endl;
	}

	Node* levelRoot2 = new Node(10);
	levelRoot2->left = new Node(20);
	levelRoot2->right = new Node(30);
	levelRoot2->left->left = new Node(40);

	cout << "\nChecking Tree 2..." << endl;
	if (isFullBinaryTree(levelRoot2)) {
		cout << "Result: This tree IS a full binary tree." << endl;
	} else {
		cout << "Result: This tree is NOT a full binary tree." << endl;
	}

	return 0;
}
