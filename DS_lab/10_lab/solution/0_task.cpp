#include <bits/stdc++.h>

/*
AVL tree is a balanced version of BST. In BST the complexity for searching a key is O(n), on the other hand, it reduces to O(log n) in AVL tree.
*/

using namespace std;
class Node
{
public:
    Node *right;
    Node *left;
    int data;
    int height;
    Node(int val)
    {
        data = val;
        right = nullptr;
        left = nullptr;
        this->height = 0;
    }
};

int getHeight(Node *node)
{
    return node ? node->height : 0;
}
void updateHeight(Node *node)
{
    if (!node)
        return;
    updateHeight(node->left);
    updateHeight(node->right);
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}
int getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node *balanceTree(Node *node)
{
    if (!node)
        return node;
    // cout << "hello" << endl;
    node->left = balanceTree(node->left);
    node->right = balanceTree(node->right);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1)
        return rightRotate(node);

    if (balance < -1)
        return leftRotate(node);

    if (balance > 1)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void displayTree(Node *node)
{
    if (!node)
        return;
    displayTree(node->left);
    cout << node->data << " " << getBalance(node) << endl;
    displayTree(node->right);
}

int main()
{
    // cout << "Hello 1";
    Node *root = new Node(10);
    root->left = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(8);

    // cout << "Hello 2" << endl;
    Node *root1 = new Node(10);
    root1->right = new Node(16);
    root1->right->left = new Node(12);
    root1->right->right = new Node(18);

    updateHeight(root);
    updateHeight(root1);
    // cout << "Hello 2" << endl;
    root = balanceTree(root);
    // cout << "Hello 2" << endl;
    root1 = balanceTree(root1);

    cout << "Displaying the first tree: " << endl;
    displayTree(root);
    cout << "Displaying the second tree: " << endl;
    displayTree(root1);

    return 0;
}
/*
After hardcoding the subtree, I updated the height of each node using updateheight() function. Then on the first tree it performed right rotate returning the node with the val 6. The tree is 

    4<-6-> 
      8<-10->nullptr

Left rotation is performed in the second tree. Updated tree is

        16
       /  \
       10    18
      /  \ 
    NULL   12

*/