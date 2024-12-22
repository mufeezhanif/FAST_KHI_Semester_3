#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<set>
#include<utility>
#include<queue>
#include<list>
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


//Construct a Binary Tree From a given PreOrder and InOrder
Node*build(vector<int>&preorder , int preStart , int preEnd , vector<int>&inorder , int inStart , int inEnd , unordered_map<int,int>mp)
{
     if(preStart > preEnd  || inStart > inEnd){
        return NULL;
     }
     Node*root = new Node(preorder[preStart]);
     int inRoot = mp[root->data];
     int numsLeft = inRoot - inStart;

     root->left = build(preorder , preStart+1 , preStart + numsLeft ,inorder , inStart  , inRoot-1 , mp);
     root->right = build(preorder , preStart + numsLeft +1 , preEnd , inorder , inRoot +1 , inEnd , mp);

     return root;

}

Node*buildTreeFromPI(vector<int>&preorder , vector<int>&inorder){
  
    unordered_map<int,int>mp;
    for(int i =0 ; i<inorder.size() ; i++){
        mp[inorder[i]] = i;
    }
    int n = preorder.size();
   Node*root = build(preorder , 0 , n-1 , inorder , 0 , n-1 , mp);

   return root;

}




//Constrcut a Binary Tree from given PostOrder and Inorder

Node*buildPSIT(vector<int>&postorder , int postStart , int postEnd , vector<int>&inorder , int inStart , int inEnd , unordered_map<int,int>mp){
    
    if(postStart > postEnd || inStart > inEnd)return NULL;

    Node*root = new Node(postorder[postEnd]);
    int inRoot = mp[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildPSIT(postorder , postStart , postStart + numsLeft -1 , inorder , inStart , inRoot-1 , mp);
    root->right = buildPSIT(postorder , postStart + numsLeft , postEnd-1 , inorder , inRoot+1 , inEnd , mp);

    return root;
}
Node*buildTreeFromPSI(vector<int>&postorder , vector<int>&inorder){
  
    unordered_map<int,int>mp;
    for(int i =0 ; i<inorder.size() ; i++){
        mp[inorder[i]] = i;
    }
    int n = postorder.size();
   Node*root = buildPSIT(postorder , 0 , n-1 , inorder , 0 , n-1 , mp);

   return root;

}



//CONSTRUCT A BINARY SEARCH TREE FROM A GIVEN PREORDER

//Approach--01
/*

since, we are given a preorder and we know when we sort the preorder it will give us the inorder of the BST that to
be formed

so by sorting the preorder we get the inorder

and we know how to construct a Binary Tree by inorder and preorder  (This Binay Tree will be a unique ie: Binary Search Tree)
*/

//Approach-02
//Using a upper bound to check if the preorder[i] is valid to put or not 
Node*buildbst(vector<int>&preorder , int &i , int bound){
     
     if(i == preorder.size() || preorder[i] > bound){
        return NULL;
     }

     Node*root = new Node(preorder[i++]);
     root->left = buildbst(preorder , i , root->data);
     root->right = buildbst(preorder , i , bound);

     return root;
}

Node*bstFromPreorder(vector<int>&preorder){
    int i = 0;
    return buildbst(preorder , i , INT_MAX);
}



//INORDER TRAVERSAL
void inorder_Traversal(Node*root){
    if(root == nullptr) return;
    
     inorder_Traversal(root->left);
     cout << root->data << " ";
     inorder_Traversal(root->right);
}



//CHECK IF A GIVEN BINARY TREE IS A HEAP or NOT

void countNode(Node*root , int &countNodes){
      if(root == NULL) return;

      countNodes++;
      countNode(root->left , countNodes);
      countNode(root->right , countNodes);
}

bool isMaxOrder(Node*root){  // check if it follows Max Heap properties
    
    if(root->left == NULL  && root->right == NULL){   //Leaf Node
        return true;
    }

    if(root->right == NULL){
        return root->data > root->left->data;
    }
   

        bool leftChild = root->data > root->left->data;
        bool rightChild = root->data > root->right->data;

        bool checkLeftSub = isMaxOrder(root->left);
        bool checkRightSub = isMaxOrder(root->right);

        return leftChild  && rightChild && checkLeftSub && checkRightSub;
}

bool isCBT(Node*root , int i , int NodeCount){    //check is a tree is complete binary tree or not
    if(root == NULL){
        return true;
    }
    if(i > NodeCount){
        return false;
    }

    bool left  = isCBT(root->left , 2*i , NodeCount);
    bool right = isCBT(root->right , 2*i+1 , NodeCount);

    return left && right;
}

bool checkHeap(Node*root){
    
    int NodeCount = 0;
    countNode(root , NodeCount);

    if(isCBT(root , 0 , NodeCount)  && isMaxOrder(root)){
        return true;
    }

    return false;

}



//CONSTRUCT A BINARY SEARCH TREE FROM A GIVEN ASCENDING SORTED ARRAY
Node*construct(vector<int>&arr , int low , int high){
     if(low > high){
        return NULL;
     }

     int mid = low + (high-low)/2;
     Node*root = new Node(arr[mid]);
     root->left = construct(arr , low , mid-1);
     root->right = construct(arr , mid+1 , high);

     return root;
}

Node*SortedArrayToBST(vector<int>&arr){
      return construct(arr , 0 , arr.size()-1);
}

int main(){

vector<int>arr = {-10,-3,0,5,9};
 
 Node*root = SortedArrayToBST(arr);

 inorder_Traversal(root);
 
}