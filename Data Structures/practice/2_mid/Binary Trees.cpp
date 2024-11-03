#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        this->data = d;
        this->right = nullptr;
        this->left = nullptr;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(nullptr); // marker for a new level

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            // End of current level
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr); // marker for the next level
            }
        }
        else
        {
            // Print current node
            cout << temp->data << " ";
            
            // Enqueue children
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// reverse level order traversal
// inOrder : LNR
// preOrder : NLR
// postOrder : LRN
// n = node ko print karwao 
// l = left child ko print karwao
// r = right child ko print karwao

void inorder(node* root){
    if (root == nullptr){
        return ;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void preorder(node* root){
    if (root == nullptr){
        return ;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){
    if (root == nullptr){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

void buildFromlevelOrder(node* &root) {
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Input for left child
        cout << "Enter left node for data " << temp->data << ": ";
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        // Input for right child
        cout << "Enter right node for data " << temp->data << ": ";
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = nullptr;

    buildFromlevelOrder(root);
    levelOrderTraversal(root);

    // // creating a tree
    // root = buildtree(root);
    // // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "Printing Level Order Traversal output:" << endl;
    // levelOrderTraversal(root);
    // cout << endl;
    
    // cout << "Inorder Traversal is: "; 
    // inorder(root); 
    // cout << endl;
    
    // cout << "Preorder Traversal is: ";
    // preorder(root); 
    // cout << endl;
    
    // cout << "Postorder Traversal is: ";
    // postorder(root);
    // cout << endl;

    return 0;
}
