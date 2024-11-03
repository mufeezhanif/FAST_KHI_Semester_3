#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data) {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
    Node *root;

public:
    AVL() {
        root = NULL;
    }

    // Helper to update height of a node
    void updateHeight(Node* node) {
        node->height = 1 + max(node->left ? node->left->height : 0, node->right ? node->right->height : 0);
    }

    // Helper to get balance factor of a node
    int balanceFactor(Node *node) {
        int hl = node->left ? node->left->height : 0;
        int hr = node->right ? node->right->height : 0;
        return hl - hr;
    }

    // Right rotation
    Node* rightRotate(Node* root) {
        Node *y = root->left;
        Node *temp = y->right;
        root->left = temp;
        y->right = root;
        updateHeight(root);
        updateHeight(y);
        return y;
    }

    // Left rotation
    Node* leftRotate(Node* root) {
        Node* y = root->right;
        Node *temp = y->left;
        root->right = temp;
        y->left = root;
        updateHeight(root);
        updateHeight(y);
        return y;
    }

    // Insert function
    Node* insert(Node *root, int d) {
        if (root == NULL) {
            return new Node(d);
        }
        if (d < root->data) {
            root->left = insert(root->left, d);
        } else if (d > root->data) {
            root->right = insert(root->right, d);
        } else {
            return root; // Duplicate values are not allowed in this AVL tree
        }

        // Update height of current node
        updateHeight(root);

        // Get the balance factor
        int bf = balanceFactor(root);

        // Right-Right (RR) Case
        if (bf == -2 && balanceFactor(root->right) == -1) {
            return leftRotate(root);
        }
        // Left-Left (LL) Case
        if (bf == 2 && balanceFactor(root->left) == 1) {
            return rightRotate(root);
        }
        // Right-Left (RL) Case
        if (bf == -2 && balanceFactor(root->right) == 1) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        // Left-Right (LR) Case
        if (bf == 2 && balanceFactor(root->left) == -1) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        return root;
    }

    // Public insert method
    void insert(int data) {
        root = insert(root, data);
    }

    // Helper function to find the minimum value node in the subtree
    Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    // Delete function
    Node* deleteNode(Node* root, int value) {
        if (root == NULL) {
            return NULL;
        }
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else { // Found the node to be deleted
            if (root->left == NULL && root->right == NULL) { // No children
                delete root;
                return NULL;
            } else if (root->left == NULL) { // One child (right)
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) { // One child (left)
                Node* temp = root->left;
                delete root;
                return temp;
            } else { // Two children
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        // Update height of current node
        updateHeight(root);

        // Get the balance factor
        int bf = balanceFactor(root);

        // Right-Right (RR) Case
        if (bf == -2 && balanceFactor(root->right) == -1) {
            return leftRotate(root);
        }
        // Left-Left (LL) Case
        if (bf == 2 && balanceFactor(root->left) == 1) {
            return rightRotate(root);
        }
        // Right-Left (RL) Case
        if (bf == -2 && balanceFactor(root->right) == 1) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        // Left-Right (LR) Case
        if (bf == 2 && balanceFactor(root->left) == -1) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        return root;
    }

    // Public delete method
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    // Print tree structure with indentation
    void printTree(Node *root, string indent = "", bool isLeft = true) {
        if (root != NULL) {
            cout << indent;
            if (isLeft) {
                cout << "L----";
                indent += "     ";
            } else {
                cout << "R----";
                indent += "|    ";
            }
            cout << root->data << endl;
            printTree(root->left, indent, true);
            printTree(root->right, indent, false);
        }
    }

    // Public method to call printTree
    void printTree() {
        printTree(root);
    }

    // Helper function to print in-order traversal
    void inorder(Node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // Public inorder traversal method
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL avl;

    // Insert nodes
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(25);
    avl.insert(5);
    avl.insert(15);
    avl.insert(1);

    // Display the tree structure
    cout << "AVL Tree Structure:" << endl;
    avl.printTree();

    // In-order traversal before deletion
    cout << "In-order traversal of the AVL tree before deletion:" << endl;
    avl.inorder();

    // Delete nodes
    avl.deleteNode(10);
    avl.deleteNode(15);

    // Display the tree structure after deletion
    cout << "AVL Tree Structure after deletion:" << endl;
    avl.printTree();

    // In-order traversal after deletion
    cout << "In-order traversal of the AVL tree after deletion:" << endl;
    avl.inorder();

    return 0;
}
