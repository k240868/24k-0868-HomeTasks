#include <iostream>
using namespace std;

class Node {
public:
    int employeeID;
    Node* left;
    Node* right;

    Node(int id) {
        employeeID = id;
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

    Node* insertRec(Node* node, int id) {
        if (node == nullptr) {
            return new Node(id);
        }

        if (id < node->employeeID) {
            node->left = insertRec(node->left, id);
        } else if (id > node->employeeID) {
            node->right = insertRec(node->right, id);
        }
        
        return node;
    }

    void insert(int id) {
        root = insertRec(root, id);
    }

    Node* findLCA(Node* node, int id1, int id2) {
        if (node == nullptr) {
            return nullptr;
        }

        if (id1 < node->employeeID && id2 < node->employeeID) {
            return findLCA(node->left, id1, id2);
        }
 
        if (id1 > node->employeeID && id2 > node->employeeID) {
            return findLCA(node->right, id1, id2);
        }
        
        return node;
    }

    void findCommonManager(int id1, int id2) {
        cout << "Finding common manager for Employee " << id1 
             << " and Employee " << id2 << "..." << endl;
             
        Node* lcaNode = findLCA(root, id1, id2);

        if (lcaNode != nullptr) {
            cout << "  > Closest Common Manager: Employee ID " 
                 << lcaNode->employeeID << endl;
        } else {
            cout << "  > No common manager found (tree is empty)." << endl;
        }
    }
};

int main() {
    BST hierarchy;

    hierarchy.insert(50);
    hierarchy.insert(30);
    hierarchy.insert(70);
    hierarchy.insert(20);
    hierarchy.insert(40);
    hierarchy.insert(60);
    hierarchy.insert(80);
    hierarchy.insert(35);

    cout << "--- Employee Hierarchy Analysis ---" << endl;

    hierarchy.findCommonManager(20, 40);
    hierarchy.findCommonManager(35, 60);
    hierarchy.findCommonManager(20, 80);

    return 0;
}
