#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int val) : left(nullptr), right(nullptr)
    {
        this->val = val;
    }
};
class BST
{
public:
    Node *root;

    BST() : root(nullptr) {};
    // INSERTION
    void insertion(int val)
    {
        Node *temp = new Node(val);

        if (!root)
        {
            root = temp;
            return;
        }
        Node *curr = root;
        Node *parent = nullptr;
        while (curr)
        {
            parent = curr;
            if (val > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (val > parent->val)
            parent->right = temp;
        else
            parent->left = temp;
    }

    // Searching
    void search(int val)
    {
        Node *mover = root;
        while (mover)
        {
            if (mover->val == val)
            {
                cout << "Value exists in the tree" << endl;
                return;
            }
            if (val > mover->val)
            {
                mover = mover->right;
            }
            else
            {
                mover = mover->left;
            }
        }

        cout << "Value not found, inserting the value" << endl;
        insertion(val);
        return;
    }

    void inOrder()
    {
        cout << "Displaying tree, traversing inorder" << endl;
        traverseInOrder(root);
        cout << endl;
    }

private:
    void traverseInOrder(Node *mover)
    {
        if (!mover)
        {
            return;
        }
        traverseInOrder(mover->left);
        cout << mover->val << " ";
        traverseInOrder(mover->right);
    }
};
int main()
{
    BST b1;
    b1.insertion(45);
    b1.insertion(4);
    b1.insertion(5);
    b1.insertion(15);
    b1.insertion(25);
    b1.inOrder();
    int a;
    cout<<"Enter value to be found: ";
    cin>>a;
    b1.search(a);
    b1.inOrder();
    return 0;
}