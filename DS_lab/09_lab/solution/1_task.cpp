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
    Node *search(int val)
    {
        if (!root)
        {
            cout << "No node exist" << endl;
            return nullptr;
        }
        Node *mover = root;
        while (mover || mover)
        {
            if (mover->val == val)
            {
                cout << "Value found and node returned" << endl;
                return mover;
            }
            else if (mover->val==val)
            {

                cout << "Value found and node returned" << endl;
                return mover;
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
        cout << "Value not found" << endl;
        return nullptr;
    }
    // Deleting
    void Deletion(int val)
    {
        Node *curr = search(val);
        if (!curr)
        {
            cout << "Entered value is not a part of tree" << endl;
            return;
        }
        root = deleteNode(root, val);
        cout << "Value deleted successfully" << endl;
    }
    // travesing

    void inOrder()
    {
        cout << "Displaying tree, traversing inorder" << endl;
        traverseInOrder(root);
        cout << endl;
    }
    void preOrder()
    {

        cout << "Displaying tree, traversing preorder" << endl;
        traversepreOrder(root);
        cout << endl;
    }
    void postOrder()
    {

        cout << "Displaying tree, traversing postorder" << endl;
        traversepostOrder(root);
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
    void traversepreOrder(Node *mover)
    {
        if (!mover)
        {
            return;
        }
        cout << mover->val << " ";
        traversepreOrder(mover->left);
        traversepreOrder(mover->right);
    }
    void traversepostOrder(Node *mover)
    {
        if (!mover)
        {
            return;
        }
        traversepostOrder(mover->left);
        traversepostOrder(mover->right);
        cout << mover->val << " ";
    }

    Node *deleteNode(Node *head, int val)
    {
        if (head == NULL)
            return head;
        if (head->val > val)
            head->left = deleteNode(head->left, val);
        else if (head->val < val)
            head->right = deleteNode(head->right, val);
        else
        {
            if (head->left == NULL)
            {
                Node *temp = head->right;
                delete head;
                return temp;
            }
            if (head->right == NULL)
            {
                Node *temp = head->left;
                delete head;
                return temp;
            }

            Node *changed = getSuccessor(head);
            head->val = changed->val;
            head->right = deleteNode(head->right, changed->val);
        }
    }
    Node *getSuccessor(Node *temp)
    {
        temp = temp->right;
        while (temp && temp->left)
            temp = temp->left;
        return temp;
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
    b1.preOrder();
    b1.postOrder();
    b1.Deletion(1);
    b1.Deletion(45);
    b1.preOrder();
    b1.postOrder();
    return 0;
}