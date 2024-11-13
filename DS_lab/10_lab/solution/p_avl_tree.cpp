#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    int height;

    Node(int val)
    {
        left = nullptr;
        right = nullptr;
        height = 0;
        data = val;
    }
};

class AVL
{
public:
    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T = x->right;
        x->right = y;
        y->left = T;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return x;
    }
    Node *rotateLeft(Node *y)
    {
        Node *x = y->right;
        Node *T = x->left;
        x->left = y;
        y->right = T;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return x;
    }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    Node *insertNode(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        else if (val < node->data)
        {
            node->left = insertNode(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertNode(node->right, val);
        }
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && val < node->left->data)
        {
            return rotateRight(node);
        }

        if (balance < -1 && val > node->right->data)
        {
            return rotateLeft(node);
        }

        if (balance > 1 && val > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && val < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void deleteVal(int val)
    {
        root = deleteNode(root, val);
    }

    Node *deleteNode(Node *node, int val)
    {
        if (!node)
            return node;

        if (val < node->data)
        {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteNode(node->right, val);
        }
        else
        {
            if (!node->left && !node->right)
            {
                Node *temp = node->left ? node->left : node->right;
                if (!temp)
                {
                    delete node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = minValNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, node->data);
            }
        }

        if (!node)
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);

        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    Node *minValNode(Node *node)
    {
        Node *curr = node;
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    void displayTree(Node *node)
{
    if (!node)
        return;
    displayTree(node->left);
    cout << node->data << " " << getBalance(node) << endl;
    displayTree(node->right);
}
};
int main()
{
    AVL t1;
    t1.insert(10);
    t1.insert(20);
    t1.insert(30);
    t1.insert(40);
    t1.insert(50);
    t1.displayTree(t1.root);
    cout<<"After insertion: "<<endl;
    t1.insert(15);
    t1.displayTree(t1.root);

    cout<<"Height of the tree: ";
    cout<< t1.getHeight(t1.root)<<endl;
    return 0;
}