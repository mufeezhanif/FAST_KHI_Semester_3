#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    int height;

    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
        height = 1;
    }
};

int getHeight(Node* root) {
    return root ? root->height : 0;
}

int getBalance(Node* root) {
    return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    else {
        return root;   // Duplicates not allowed
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
     
    // Balance check
    int balance = getBalance(root);

    // Unbalancing cases
    // LL case
    if (balance > 1 && key < root->left->data) {
        return rightRotation(root);
    }

    // RR case
    if (balance < -1 && key > root->right->data) {
        return leftRotation(root);
    }

    // LR case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
     
    //balanced Tree
    return root; 
}

//DeleteNode from AVL TREE

Node*deleteNode(Node*root , int key){

    if(!root) return root;

    if(key < root->data){
        root->left = deleteNode(root->left , key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right , key);
    }
    else{  // key Found

     // 3-cases
     // leaf Node
     if(!root->left && !root->right){
        delete root;
        return nullptr;
     }

      // Single Child
      // Left Child
     else if(!root->right &&  root->left){
        Node*left = root->left;
        delete root;
        return left;
      }

      // Right Child
     else if(!root->left  &&  root->right){
         Node*right = root->right;
         delete root;
         return right;
      }

      //both child
      else{
           
           // find the right side's smallest element (inordered successor)
           Node*curr = root->right;
           while(curr->left){
            curr = curr->left;
           }

           root->data = curr->data;
           root->right = deleteNode(root->right , curr->data);
      }  
        
    }

    //update Height
    root->height = 1 + max(getHeight(root->left) , getHeight(root->right));

    //Check Balancing

    int Balance = getBalance(root);

    if(Balance > 1){
            //LL
           if(getBalance(root->left) >= 0){  
              return rightRotation(root);
           }
           // LR
           else{  
               root->left = leftRotation(root->left);
               return rightRotation(root);
           }
    }
    else if ( Balance < -1 ){
             // RR
            if( getBalance(root->right) <= 0){  
                 return leftRotation(root);
            }
            // RL
            else{
                  root->right = rightRotation(root->right);
                  return leftRotation(root);
            }
    }

    return root;  // Tree is Balanced
}



void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    preorder(root);
     cout << endl;
    root = deleteNode(root , 100);
    preorder(root);
    cout << endl;
    root = deleteNode(root , 50);
    preorder(root);

    return 0;
}
