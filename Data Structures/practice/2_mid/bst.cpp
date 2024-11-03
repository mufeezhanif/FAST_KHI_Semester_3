#include <iostream>
using namespace std;

class BST {
    // Each node in the BST is represented by this struct
    struct Node {
        int data;     // Holds the value of the node
        Node* left;   // Pointer to the left child
        Node* right;  // Pointer to the right child

        // Constructor to initialize a new node with given value
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;  // Root node of the BST

    // Recursive helper function to insert a new node with the given value
    void insertNode(Node*& root, int val) {
        if (root == nullptr) {
            root = new Node(val); // Create a new node if root is null
            return;
        }
        if (val < root->data) {
            insertNode(root->left, val); // Insert into the left subtree
        } else if (val > root->data) {
            insertNode(root->right, val); // Insert into the right subtree
        }
        // If the value is equal to root->data, do nothing (no duplicates allowed)
    }

    // Iterative search function for a node with a given key
    Node* searchNode(Node* root, int key) {
        // Loop until the node with the key is found or we reach a null pointer
        while (root != nullptr) {
            if (key == root->data) return root; // Key found
            root = (key < root->data) ? root->left : root->right; // Move left or right
        }
        return nullptr; // Key not found
    }

    // Recursive search function for a node with a given key
    bool searchRecursion(Node* node, int key) {
        if (node == nullptr) return false; // Base case: key not found
        if (node->data == key) return true; // Key found
        // Recur into left or right subtree
        return (key < node->data) ? searchRecursion(node->left, key) : searchRecursion(node->right, key);
    }

    // Recursive Preorder Traversal: Visit root, left subtree, then right subtree
    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";   // Visit root node
        preorder(root->left);        // Traverse left subtree
        preorder(root->right);       // Traverse right subtree
    }

    // Recursive Inorder Traversal: Visit left subtree, root, then right subtree
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);         // Traverse left subtree
        cout << root->data << " ";   // Visit root node
        inorder(root->right);        // Traverse right subtree
    }

    // Recursive Postorder Traversal: Visit left subtree, right subtree, then root
    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);       // Traverse left subtree
        postorder(root->right);      // Traverse right subtree
        cout << root->data << " ";   // Visit root node
    }

    // Calculates the height (or depth) of the BST
    int height(Node* root) {
        if (root == nullptr) return -1;  // Base case: height of empty tree is -1
        int lheight = height(root->left);   // Height of left subtree
        int rheight = height(root->right);  // Height of right subtree
        return max(lheight, rheight) + 1;   // Return the maximum of left and right subtree heights plus 1 for the root
    }

    // Helper function to print nodes at a given level (used for BFS)
    void printGivenLevel(Node* root, int level) {
        if (root == nullptr) return;
        if (level == 0) {
            cout << root->data << " ";  // Print nodes at the current level
        } else {
            printGivenLevel(root->left, level - 1);  // Recur on left subtree
            printGivenLevel(root->right, level - 1); // Recur on right subtree
        }
    }

    // Level-order traversal using recursion (Breadth-First Search)
    void printLevelOrderBFS(Node* root) {
        int h = height(root);  // Get height of the tree
        for (int i = 0; i <= h; i++) {
            printGivenLevel(root, i);
            cout << endl;// Print nodes at each level
        }
    }

    // Finds the node with the minimum value (leftmost node in a BST)
    Node* minValueNode(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left; // Move to the leftmost node
        }
        return node;
    }

    // Recursive function to delete a node with the given value
    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) return root;  // Base case: tree is empty

        // Traverse to the node to delete
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children: get the inorder successor
            Node* temp = minValueNode(root->right);
            root->data = temp->data; // Copy successor's data to this node
            root->right = deleteNode(root->right, temp->data); // Delete the successor
        }
        return root;
    }

public:
    // Constructor to initialize an empty tree
    BST() : root(nullptr) {}

    // Public wrapper for recursive insert function
    void insertNode(int val) { insertNode(root, val); }

    // Public wrapper for iterative search
    void searchNode(int key) {
        Node* foundNode = searchNode(root, key);
        cout << (foundNode ? "Element found!" : "Element not found!") << endl;
    }

    // Public wrapper for recursive search
    void searchRecursion(int key) {
        cout << (searchRecursion(root, key) ? "Element found!" : "Element not found!") << endl;
    }

    // Public wrapper for preorder traversal
    void preorder() { preorder(root); }

    // Public wrapper for inorder traversal
    void inorder() { inorder(root); }

    // Public wrapper for postorder traversal
    void postorder() { postorder(root); }

    // Public wrapper for level-order traversal (BFS)
    void printLevelOrderBFS() { printLevelOrderBFS(root); }

    // Public wrapper for deletion
    void deleteNode(int key) {
        root = deleteNode(root, key);
        cout << "Node deleted!" << endl;
    }
};

int main() {
    BST tree;
    tree.insertNode(20);
    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(55);
    tree.insertNode(10);

    cout << "Inorder traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;

    cout << "Level Order (BFS): ";
    tree.printLevelOrderBFS();
    cout << endl;

    cout << "Search for 55: ";
    tree.searchRecursion(55);

    tree.deleteNode(10);
    cout << "Level Order (BFS) after deletion: ";
    tree.printLevelOrderBFS();
    cout << endl;

    return 0;
}
