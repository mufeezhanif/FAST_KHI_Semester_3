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

    bool checkIfBST()
    {
        int arr[100]; // let's say we donot have more than 100 elements in a tree
        int ind = 0;
        inOrder(arr, ind);

        for (int i = 0; i < ind - 1; ++i)
        {
            if (arr[i + 1] < arr[i])
                return false;
        }
        return true;
    }
    void inOrder(int arr[], int &ind)
    {
        cout << "Displaying tree, traversing inorder" << endl;
        traverseInOrder(root, arr, ind);
        cout << endl;
    }

private:
    void traverseInOrder(Node *mover, int arr[], int &ind)
    {
        if (!mover)
        {
            return;
        }
        traverseInOrder(mover->left, arr, ind);
        arr[ind++] = mover->val;
        traverseInOrder(mover->right, arr, ind);
    }
};
int main()
{
    BST b1;
    b1.root = new Node(10);
    b1.root->left = new Node(5);
    b1.root->right = new Node(20);
    b1.root->right->left = new Node(9);
    b1.root->right->right = new Node(30);
    
    if(b1.checkIfBST()){
        cout<<"Yes, it is a bst"<<endl;
    }
    else
        cout<<"No, it is not a bst"<<endl;
    return 0;
}