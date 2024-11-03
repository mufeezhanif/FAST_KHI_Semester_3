#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class FullBinaryTree
{
public:
    Node *root;

    FullBinaryTree() : root(nullptr) {}

    // Function to insert nodes in a full binary tree
    Node *insert(Node *node, int val)
    {
        if (!node)
        {
            return new Node(val);
        }

        if (!node->left)
        {
            node->left = insert(node->left, val);
        }
        else if (!node->right)
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Pre-order traversal to display the tree
    void preOrder(Node *node)
    {
        if (node)
        {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Function to find the last node and also return the parent of the last node
    Node *findLastNode(Node *node, Node *&parent)
    {
        if (!node)
            return nullptr;

        if (!node->left && !node->right)
            return node; // Leaf node

        // Check for left subtree
        parent = node; // Set parent
        Node *last = findLastNode(node->right, parent);
        if (last)
            return last;                         // Found in right subtree
        return findLastNode(node->left, parent); // Search in left subtree
    }

    // Function to delete a node
    void deleteNode(int key)
    {
        if (!root)
            return;

        // If the tree has only one node
        if (root->data == key && !root->left && !root->right)
        {
            delete root;
            root = nullptr;
            return;
        }

        Node *keyNode = nullptr;
        Node *parent = nullptr;
        Node *something = nullptr;
        Node *lastNode = findLastNode(root, parent);

        // Perform a search for the key node and track its parent

        searchForNode(root, key, keyNode, something);
        // If the key node was found, replace it with the last node
        if (keyNode)
        {
            keyNode->data = lastNode->data;   // Replace value
            deleteLastNode(parent, lastNode); // Delete the last node
        }
    }

    // Function to search for the node and its parent
    void searchForNode(Node *node, int key, Node *&keyNode, Node *&parent)
    {
        if (!node)
            return;

        if (node->data == key)
        {
            keyNode = node;
            return;
        }

        parent = node; // Set parent
        searchForNode(node->left, key, keyNode, parent);
        if (!keyNode) // Continue searching in the right subtree if not found
            searchForNode(node->right, key, keyNode, parent);
    }

    // Function to delete the last node
    void deleteLastNode(Node *parent, Node *lastNode)
    {
        if (parent->left == lastNode)
        {
            parent->left = nullptr;
        }
        else if (parent->right == lastNode)
        {
            parent->right = nullptr;
        }
        delete lastNode;
    }
};

int main()
{
    FullBinaryTree tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 1);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 7);

    std::cout << "Pre-order traversal before deletion: ";
    tree.preOrder(tree.root);
    std::cout << std::endl;

    // Delete a node
    int keyToDelete = 3;
    tree.deleteNode(keyToDelete);

    std::cout << "Pre-order traversal after deleting " << keyToDelete << ": ";
    tree.preOrder(tree.root);
    std::cout << std::endl;

    return 0;
}