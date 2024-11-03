#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  int height;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    height = 1;
    left = nullptr;
    right = nullptr;
  }
};

int getHeight(Node *root)
{
  if (root)
  {
    return root->height;
  }
  return 0;
}
int getBalance(Node *root)
{
  return getHeight(root->left) - getHeight(root->right);
}
// Left Rotation
Node *leftRotate(Node *root)
{

  Node *child = root->right;
  Node *childLeft = child->left;

  child->left = root;
  root->right = childLeft;

  // update Height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}
// Right Rotate
Node *rightRotate(Node *root)
{

  Node *child = root->left;
  Node *childRight = root->right;

  child->right = root;
  root->left = childRight;

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}
// Duplicates are not being inserted
Node *insert(Node *root, int key)
{

  // null node
  if (root == nullptr)
  {
    return new Node(key);
  }

  if (key < root->data)
  {
    root->left = insert(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = insert(root->right, key);
  }
  else
  {
    return root; // duplicates not allowed
  }

  // update height

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // balance check
  int balance = getBalance(root);

  // Unbalancing cases
  // Left Left Case -> right rotate the top value (from 3 values)
  if (balance > 1 && key < root->left->data)
  {
    return rightRotate(root);
  }

  // Right Right Case -> left rotate the top value
  else if (balance < -1 && root->right->data < key)
  {
    return leftRotate(root);
  }

  // Left Right Case -> left rotate the middle one then right rotate the top
  else if (balance > 1 && key > root->left->data)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Left Case
  else if (balance < -1 && root->right->data > key)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  // Balanced case
  else
  {
    return root;
  }
}
// DELETION OF NODE
Node *DeleteNode(Node *root, int key)
{

  if (!root)
    return nullptr;

  if (key < root->data)
  { // lesser
    root->left = DeleteNode(root->left, key);
  }
  else if (key > root->data)
  { // greater
    root->right = DeleteNode(root->right, key);
  }
  else
  { // element FOUND

    // 3 conditions
    // Leaf Node

    if (!root->left && !root->right)
    {
      delete root;
      return nullptr;
    }

    // Single Child
    //  Left Child
    else if (root->left && !root->right)
    {
      Node *left = root->left;
      delete root;
      return left;
    }

    // Right Child
    else if (root->right && !root->left)
    {
      Node *right = root->right;
      delete root;
      return right;
    }

    // both child
    else
    {

      // Right Side smallest Element
      Node *curr = root->right;
      while (curr->left)
      {
        curr = curr->left;
      }

      root->data = curr->data;
      root->right = DeleteNode(root->right, curr->data);
    }
  }

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // check balancing
  int balance = getBalance(root);

  if (balance > 1)
  {
    // LL
    if (getBalance(root->left) >= 0)
    {
      return rightRotate(root);
    }
    // LR
    else
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  else if (balance < -1)
  {
    // RR
    if (getBalance(root->right) >= 0)
    {
      return leftRotate(root);
    }
    // RL
    else
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }

  return root; // Tree is balanced
}
void preorder(Node *root)
{
  if (root == nullptr)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main()
{

  Node *root = nullptr;

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
  root = DeleteNode(root, 50);
  preorder(root);
}
