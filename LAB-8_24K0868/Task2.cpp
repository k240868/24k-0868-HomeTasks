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

int countNodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	return countLeaves(root->left) + countLeaves(root->right);
}

int findHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);

	int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;

	return 1 + maxHeight;
}

int main() {
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(15);
	root->left->left = new Node(3);
	root->left->right = new Node(7);
	root->right->right = new Node(18);
	root->left->left->left = new Node(1);

	cout << "Binary Tree Analysis" << endl;
	cout << "--------------------" << endl;

	cout << "Total Nodes: " << countNodes(root) << endl;
	cout << "Leaf Nodes: " << countLeaves(root) << endl;
	cout << "Tree Height: " << findHeight(root) << endl;

	return 0;
}
