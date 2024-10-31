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

void findBetweenRange(Node * root, int & count, int a, int b){
        if(!root) return;
        if(root->val>= a && root->val <= b){
        ++count;
        findBetweenRange(root->left,count, a,b);
        findBetweenRange(root->right,count, a,b);
        
        }
        if(root->val<a)
        findBetweenRange(root->right,count, a,b);
        else if(root->val > b)
        findBetweenRange(root->left,count, a,b);
    }
int main()
{
    BST b1;
    b1.insertion(5);
    b1.insertion(1);
    b1.insertion(10);
    b1.insertion(15);
    b1.insertion(40);
    b1.insertion(100);

    int a, b;
    cin>>a>>b;
    int count =0;
    findBetweenRange(b1.root,count, a, b);
    cout<<"Count: "<<count<<endl;
    return 0;
}