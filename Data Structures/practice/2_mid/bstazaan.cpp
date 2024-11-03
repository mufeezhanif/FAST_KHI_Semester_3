#include <iostream>
#include <iomanip> // for std::setw
using namespace std;

struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data) : data(data) {}
    Node(int data, Node *left) : data(data), left(left) {}
    Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}

    ~Node()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

class Tree
{
public:
    Node *root = nullptr;

    void Insert(int data)
    {
        if (root)
        {
            Node *prev = nullptr;
            Node *curr = root;
            while (curr)
            {
                prev = curr;
                if (data > curr->data)
                {
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            if (data >= prev->data)
            {
                prev->right = new Node(data);
            }
            else
            {
                prev->left = new Node(data);
            }
        }
        else
        {
            root = new Node(data);
        }
    }

    void remove(int data)
    {
        Node *prev = nullptr;
        Node *curr = root;

        while (curr && curr->data != data)
        {
            prev = curr;
            if (data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }

        if (!curr)
        {
            return; // Node not found
        }

        if (!curr->left && !curr->right)
        {
            // Case 1: Node has no children
            if (curr == root)
            {
                delete root;
                root = nullptr;
            }
            else if (prev->left == curr)
            {
                prev->left = nullptr;
            }
            else
            {
                prev->right = nullptr;
            }
            delete curr;
        }
        else if (!curr->left || !curr->right)
        {
            // Case 2: Node has one child
            Node *child = (curr->left) ? curr->left : curr->right;
            if (curr == root)
            {
                root = child;
            }
            else if (prev->left == curr)
            {
                prev->left = child;
            }
            else
            {
                prev->right = child;
            }
            delete curr;
        }
        else
        {
            // Case 3: Node has two children
            Node *temp = curr->left;
            Node *parent = curr;
            while (temp->right)
            {
                parent = temp;
                temp = temp->right;
            }
            curr->data = temp->data;
            if (parent->right == temp)
            {
                parent->right = temp->left;
            }
            else
            {
                parent->left = temp->left;
            }
            delete temp;
        }
    }

    void Traversal(Node *val)
    {
        if (val)
        {
            Traversal(val->left);
            cout << val->data << endl;
            Traversal(val->right);
        }
    }

    // Function to display the tree
    void
    display(Node *node, int space)
    {
        if (node == nullptr)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        display(node->right, space);

        // Print current node after space
        cout << endl;
        cout << setw(space) << node->data << endl;

        // Process left child
        display(node->left, space);
    }

    void insert(int data)
    {
        Insert(data);
    }

    void display()
    {
        display(root, 0);
    }
};

int main()
{
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.display();
    tree.remove(7);
    cout << "After Removing Values:" << endl;
    tree.display();
    tree.Traversal(tree.root);
    return 0;
}