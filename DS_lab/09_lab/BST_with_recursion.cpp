#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorder(root->left);
    
    cout << root->data << " ";
    
    inorder(root->right);
}

Node* insert(Node* root, int val) {
    if (root == nullptr) {
    	Node* newNode = new Node(val);
    	return newNode;
        //return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

        Node* findMin(Node* node) {
            Node* current = node;
            while (current && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        Node* deleteNode(Node* root, int key) {
            if (root == nullptr) {
                return root;
            }

            // Traverse the tree to find the node to be deleted
            if (key < root->data) {
                root->left = deleteNode(root->left, key);  
            } else if (key > root->data) {
                root->right = deleteNode(root->right, key); 
            } else {
                // Node to be deleted found
                // Case 1: Node has no child (leaf node)
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                }
                // Case 2: Node has one child (left or right)
                else if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // Case 3: Node has two children
                Node* temp = findMin(root->right);  // Find the in-order successor (smallest in the right subtree)
                root->data = temp->data;  // Replace the data of the node to be deleted with the successor's data
                root->right = deleteNode(root->right, temp->data);  // Delete the successor node
            }
            return root;
        }

        void deleteValue(Node* root, int key) {
            root = deleteNode(root, key);
        }

int main() {
    Node* root = nullptr;
    root = insert(root, 42);
    insert(root, 28);
    insert(root, 62);
    insert(root, 31);
    insert(root, 21);
    insert(root, 71);
    insert(root, 59);
    insert(root, 23);
    insert(root, 17);
    insert(root, 57);
    insert(root, 35);
    insert(root, 30);
    insert(root, 82);
     insert(root, 60);
    insert(root, 67);

    cout << "Inorder traversal of the BST: \n";
    inorder(root);
    cout << endl;
    deleteValue(root, 31);
    cout << "AFter Deletion Inorder traversal of the BST: \n";
    inorder(root);
    cout << endl;

    return 0;
}
