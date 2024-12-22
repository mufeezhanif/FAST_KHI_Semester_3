#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<utility>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;


class Node{
public:
    int data;
    Node*left;
    Node*right;

public:
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(int data , Node*left , Node*right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node*BuildTree(Node*root){
  cout << "Enter the data : " ;
  int d;
  cin >> d;
  root = new Node(d);

  if(d == -1){   // assumption to end Tree
    return NULL;
  }

  cout << "Enter the data for Inserting in Left of " << d << endl;
  root->left = BuildTree(root->left);

  
  cout << "Enter the data for Inserting in Right of " << d << endl;
  root->right = BuildTree(root->right);

  return root;

}



//Creating a Degenerate Binary Tree
//Left-Skewed
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    }
    else {
        root->left = insert(root->left, data);
    }
    return root;
}





//Check if a Binary Tree is Perfect Binary Tree or Not

int calculateDepth(Node*root){
    int d= 0;
    while(root != nullptr){
        d++;
        root = root->right;         //calculate depth from one side , to check the tree is perfect or not
    }
    return d;
}

/* This function tests if a binary tree is perfect
   or not. It basically checks for two things :
   1) All leaves are at same level
   2) All internal nodes have two children */


bool isPerfectTree(Node*root , int d , int level = 0){
      if(root == NULL) return false;
  
       //at leaves
      if(root->left == NULL  && root->right == NULL){
        return (d == level + 1);
      }

      // any side of the root reached at end and other not , means not a perfect BT
      if(root->left == NULL  || root->right == NULL){
        return false;
      }

      return isPerfectTree(root->left , d , level+1)  && isPerfectTree(root->right , d , level+1);
}



bool isPerfect(Node*root){
    int d = calculateDepth(root);

    return isPerfectTree(root , d);

}



//Convert Array into Binary Tree
Node*convertArrToBT(vector<int>&arr){
    if(arr.empty()) return NULL;

   Node*root = new Node(arr[0]);
   queue<Node*>q;
   q.push(root);

   int i = 1;
   while(i < arr.size()){
    Node*curr = q.front();
    q.pop();

    if(i<arr.size()){
        curr->left = new Node(arr[i] == -1 ? NULL : arr[i]);
        q.push(curr->left);
        i++;
    }

    if(i<arr.size()){
        curr->right = new Node(arr[i]== -1 ? NULL : arr[i]);
        q.push(curr->right);
        i++;
    }

   }

   while(!q.empty())q.pop();   //empty the queue;

   return root;

}


//LEVEL ORDER TRAVERSAL or BREADTH FIRST SEARCH(BFS)
void LevelOrder_Traversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // a seperator to print tree in a "TREE FORMAT" 
    //this seperator will indicate if NULL comes in the queue and still the queue isn't empty then again we put a seperator and an "endl"

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);   // seperator for Next Level 
            }

        }
        else{
            
            cout << temp->data<< " ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
 
    }


}

//INORDER TRAVERSAL
void InOrder_Traversal(Node*root){  //LNR
    if(root == NULL) return;
    InOrder_Traversal(root->left);
       cout<<root->data <<" ";
     InOrder_Traversal(root->right);
}
//INORDER->Iterative
void InorderIterative(Node*root){
    if(root == NULL) return;
    stack<Node*>s;

    Node*current = root;

    while(current !=  NULL  || !s.empty())
    {
         // Reach the leftmost node of the current node
          while(current != NULL){
            s.push(current);
            current = current->left;
          }

          current = s.top();
          s.pop();

          cout << current->data << " "; //N
         // go to the right of subtree
          current = current->right;
    }

}


//PRE-ORDER TRAVERSAL
void PreOrder_Traversal(Node*root){  //NLR
    if(root == NULL) return;

    cout << root->data << " ";
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
}
//PRE-ORDER->Iterative
void PreorderIterative(Node*root){
    if(root == NULL) return;
    
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node*current = s.top();
        s.pop();

        cout << current->data << " ";

        if(current->right){
            s.push(current->right);
        }

        if(current->left){
            s.push(current->left);
        }
    }  
}


//POST-ORDER TRAVERSAL
void PostOrder_Traversal(Node*root){  //LRN
    if(root == NULL) return;

    PostOrder_Traversal(root->left);
    PostOrder_Traversal(root->right);

    cout << root->data <<  " ";

}
//POST-ORDER->Iterative
void PostorderIterative(Node*root){
    
   if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);
    Node* node;

    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}


//count number of Leaf Nodes
void traverse(Node*root , int &count){
     if(root == NULL)return;

     traverse(root->left , count);

     if(root->left == NULL   && root->right == NULL){
        count++;
     }

     traverse(root->right , count);
}
int countLeafNode(Node*root){
    int cnt = 0;
    traverse(root , cnt);
    return cnt;
     
     
}


//Maximum depth of a TREE
int maxDepth(Node*root){
    if(root == NULL) return 0;

   /*
    //Recursive
    int LD = maxDepth(root->left);
    int RD = maxDepth(root->right);

    return 1 + max(LD , RD);
    */

   queue<Node*>q;
   q.push(root);
   int depth = 0;

   while(!q.empty()){
         int levelsize = q.size();
    for(int i = 0 ; i<levelsize ; i++){
        Node*temp = q.front();
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    depth++;
   }
   

   return depth;
}



//Check if a given Binary Tree is BST or NOT
int bstLMax(Node* root) {
    if (root == nullptr) {
        return INT_MIN;  // Minimum possible value if there is no left subtree
    }
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

int bstRMin(Node* root) {
    if (root == nullptr) {
        return INT_MAX;  // Maximum possible value if there is no right subtree
    }
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

bool isValidBST(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int leftMax = bstLMax(root->left);
    int rightMin = bstRMin(root->right);

    if ((root->left && leftMax >= root->data) || (root->right && rightMin <= root->data)) {
        return false;
    }

    bool left = isValidBST(root->left);
    bool right = isValidBST(root->right);

    return left && right;
}



//INSERT a given Node in a Binary Search Tree

Node*insertNode(Node*root , int key)
{
     if(root == NULL){
        return new Node(key);
     }

     Node*temp = root;
     while(true){
         if(temp->data <= key){
              if(temp->right != nullptr){    //insert at leaf -->always
                temp = temp->right;
              }
              else{
                temp->right = new Node(key);
                break;
              }
         }
         else{
              if(temp->left != nullptr){
                temp = temp->left;
              }
              else{
                temp->left = new Node(key);
                break;
              }
         }
     }

     return root;
}



//Delete a given Node from a Binary Search Tree
Node* findLastRight(Node* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}


Node*helper(Node*root){

    if(root->right == nullptr){
        return root->left;
    }

    else if(root->left == nullptr){
        return root->right;
    }

    Node*rightchild = root->right;
    Node*leftRight = findLastRight(root->left);

    leftRight->right = rightchild;

    return root->left;

}

Node*deleteNode(Node*root , int key){
    if(root == nullptr) return nullptr;

    Node*dummy = root;

    if(root->data == key){
        return helper(root);
    }
  
  while(root != NULL){
    
    if(root->data > key){
    
         if(root->left != nullptr  &&  root->left->data == key){
            root->left = helper(root->left);
            break;
         }
         else{
            root = root->left;
         }

    }
    else{

         if(root->right != nullptr  && root->right->data == key){
              root->right = helper(root->right);
              break;
         }
         else{
            root = root->right;
         }
    }
}

 return dummy;

}


//KTH LARGEST
 vector<int>arr;
    void solve(Node*root){
       if(root == NULL){
           return;
       }    
       
       arr.push_back(root->data);
       solve(root->left);
       solve(root->right);
    }

 int kthLargest(Node *root, int K)
    {
        //Your code here
        arr.clear();
        solve(root);
        sort(arr.begin() , arr.end());
        
        return arr[arr.size()-K];
    
        
    }


    bool isFullTree(Node*root){
         if(root == nullptr) return true;

          if(root->left  && !root->right) return false;
          if(root->right &&  !root->left) return false;
         return isFullTree(root->left) && isFullTree(root->right);
    }


bool isCompleteBinaryTree(Node* root) {
    if (!root) return true; // An empty tree is complete

    queue<Node*> q;
    q.push(root);

    bool flag = false; // Flag to mark the occurrence of the first non-full node

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check the left child
        if (temp->left) {
            if (flag) return false; // If flag is set and we still find nodes, the tree is not complete
            q.push(temp->left);
        } else {
            flag = true; // Set flag as left child is missing
        }

        // Check the right child
        if (temp->right) {
            if (flag) return false; // If flag is set and we still find nodes, the tree is not complete
            q.push(temp->right);
        } else {
            flag = true; // Set flag as right child is missing
        }
    }

    return true;
}




int main() {
   Node* root = nullptr;

    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->right->left = new Node(12);
    root->right->right = new Node(16);

    cout << isFullTree(root);


  if (isCompleteBinaryTree(root)) {
        cout << "The tree is complete." << endl;
    } else {
        cout << "The tree is not complete." << endl;
    }
  
   
    return 0;
}