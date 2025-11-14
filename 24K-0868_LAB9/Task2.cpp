#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

class AVLTree {
public:
    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* newNode(int key) {
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return(node);
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node* insert(Node* node, int key) {
        if (node == NULL)
            return(newNode(key));

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node *root) {
        if(root != NULL) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main() {
    AVLTree avl;
    Node *root = NULL;

    root = avl.insert(root, 50);
    root = avl.insert(root, 30);
    root = avl.insert(root, 70);
    root = avl.insert(root, 20);
    root = avl.insert(root, 40);
    root = avl.insert(root, 60);
    root = avl.insert(root, 80);

    cout << "Initial tree (pre-order): \n";
    avl.preOrder(root);
    cout << "\n\n";

    root = avl.insert(root, 55);

    cout << "Tree after inserting 55 (pre-order): \n";
    avl.preOrder(root);
    cout << "\n\n";
    
    cout << "Tree after forcing a Left Rotation on the root: \n";
    root = avl.leftRotate(root);
    avl.preOrder(root);
    cout << "\n";

    return 0;
}
