#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int id;
    int quantity;

    Node(int id, int quantity) : left(nullptr), right(nullptr)
    {
        this->id = id;
        this->quantity = quantity;
    }
};
class BST
{
public:
    Node *root;

    BST() : root(nullptr) {};
    // INSERTION
    void insertionAccQuantity(int id, int quantity)
    {
        Node *temp = new Node(id, quantity);

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
            if (quantity > curr->quantity)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (quantity > parent->quantity)
            parent->right = temp;
        else
            parent->left = temp;
    }
    void insertion(int id, int quantity)
    {
        Node *temp = new Node(id, quantity);

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
            if (id > curr->id)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (id > parent->id)
            parent->right = temp;
        else
            parent->left = temp;
    }

    // Searching
    Node *search(int id)
    {
        if (!root)
        {
            cout << "No node exist" << endl;
            return nullptr;
        }
        Node *mover = root;
        while (mover)
        {
            if (mover->id == id)
            {
                cout << "id found , quanity: " << mover->quantity << endl;
                return mover;
            }
            if (id > mover->id)
            {
                mover = mover->right;
            }
            else
            {
                mover = mover->left;
            }
        }
        cout << "id not found" << endl;
        return nullptr;
    }
    // Deleting
    void update(int id, int updatedQuantity)
    {
        Node *curr = search(id);
        if (!curr)
        {
            cout << "Entered id is not a part of tree" << endl;
            return;
        }
        curr->quantity = updatedQuantity;
        cout << "Quantity updated" << endl;
    }

    // highest quantity
    Node *returnHighestQuantityNode()
    {
        if (!root)
        {
            cout << "No node exists in the tree" << endl;
            return nullptr;
        }
        BST tempTree;
        tempTree.copyTree(root);
        Node *temp = tempTree.root;
        while (temp->right)
        {
            temp = temp->right;
        };
        return temp;
    }
    void printTree()
    {
        // cout << "Displaying tree, traversing inorder" << endl;
        inOrder(root);
        cout << endl;
    }

private:
    void copyTree(Node *newRoot)
    {
        if (!newRoot)
            return;
        copyTree(newRoot->left);
        insertionAccQuantity(newRoot->id, newRoot->quantity);
        copyTree(newRoot->right);
    }
    void inOrder(Node *mover)
    {
        if (!mover)
        {
            return;
        }
        inOrder(mover->left);
        cout << mover->id << " " << mover->quantity << endl;
        inOrder(mover->right);
    }
};
int main()
{
    BST b1;
    b1.insertion(113, 1);
    b1.insertion(13, 0);
    b1.insertion(133, 5);
    b1.insertion(423, 0);
    b1.insertion(453, 2);
    b1.printTree();
    // b1.search(133);
    b1.update(43, 3);
    Node * maxQuanity=   b1.returnHighestQuantityNode();
    cout<<maxQuanity->id<<" "<<maxQuanity->quantity<<endl;
    return 0;
}