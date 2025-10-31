#include <iostream>
using namespace std;

class Node {
public:
    int productID;
    int quantity;
    Node* left;
    Node* right;

    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insertRec(Node* node, int id, int qty) {
        if (node == nullptr) {
            return new Node(id, qty);
        }

        if (id < node->productID) {
            node->left = insertRec(node->left, id, qty);
        } else if (id > node->productID) {
            node->right = insertRec(node->right, id, qty);
        } else {
            node->quantity = qty;
        }
        return node;
    }

    void insert(int id, int qty) {
        root = insertRec(root, id, qty);
    }

    void search(int id) {
        Node* current = root;
        while (current != nullptr) {
            if (id == current->productID) {
                cout << "  Product ID: " << id << ", Current Quantity: " << current->quantity << endl;
                return;
            } else if (id < current->productID) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "  Product ID: " << id << " not found." << endl;
    }

    void findMaxQtyRec(Node* node, Node*& maxNode) {
        if (node == nullptr) {
            return;
        }

        if (node->quantity > maxNode->quantity) {
            maxNode = node;
        }
        
        findMaxQtyRec(node->left, maxNode);
        findMaxQtyRec(node->right, maxNode);
    }

    void findMaxQuantity() {
        if (root == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        Node* maxNode = root;
        findMaxQtyRec(root, maxNode);

        cout << "Product with highest quantity:" << endl;
        cout << "  Product ID: " << maxNode->productID 
             << " (Quantity: " << maxNode->quantity << ")" << endl;
    }
};

int main() {
    BST inventory;

    cout << "--- Initializing Inventory ---" << endl;
    inventory.insert(102, 50);
    inventory.insert(105, 30);
    inventory.insert(101, 60);
    inventory.insert(103, 25);
    inventory.insert(107, 80);

    cout << "\n--- Searching for Products ---" << endl;
    inventory.search(101);
    inventory.search(103);

    cout << "\n--- Finding Max Quantity ---" << endl;
    inventory.findMaxQuantity();

    cout << "\n--- Updating Product 101 ---" << endl;
    inventory.insert(101, 95);
    inventory.search(101);

    cout << "\n--- Finding New Max Quantity ---" << endl;
    inventory.findMaxQuantity();

    cout << "\n--- Searching for Non-Existent Product ---" << endl;
    inventory.search(999);

    return 0;
}
