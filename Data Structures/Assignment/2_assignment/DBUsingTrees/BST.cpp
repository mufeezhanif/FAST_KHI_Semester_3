#include "BST.h"

BST::BST()
{
    root = nullptr;
    size = 0;
}

void BST::insert(int id, string name, int age)
{
    // Considering that user will enter unique ids only
    Node *newNode = new Node(id, name, age);
    ++size;
    if (!root)
    {
        root = newNode;
        return;
    }
    Node *mover = root;

    while (mover)
    {
        if (id > mover->id)
        {
            if (mover->right)
            {
                mover = mover->right;
            }
            else
            {
                mover->right = newNode;
                break;
            }
        }
        else if (id < mover->id)
        {
            if (mover->left)
            {
                mover = mover->left;
            }
            else
            {
                mover->left = newNode;
                break;
            }
        }
    }
}

void BST::deleteVal(int id)
{
    if (!root)
    {
        cout << "Tree is empty\n";
        return;
    }
    if (size == 1 && root->id == id)
    {
        delete root;
        root = nullptr;
        --size;
        return;
    }

    root = deleteValNode(root, id);
}

Node *BST::deleteValNode(Node *head, int id)
{
    if (!head)
        return nullptr;

    if (id < head->id)
    {
        head->left = deleteValNode(head->left, id);
    }
    else if (id > head->id)
    {
        head->right = deleteValNode(head->right, id);
    }
    else
    {
        --size;

        if (!head->left || !head->right)
        {
            Node *temp = head->left ? head->left : head->right;
            delete head;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(head);
            head->copyObj(succ);
            head->right = deleteValNode(head->right, succ->id);
        }
    }
    return head;
}

Node *BST::getSuccessor(Node *head)
{
    Node *current = head->right;
    while (current && current->left)
    {
        current = current->left;
    }
    return current;
}

Node *BST::findEntry(int id)
{
    Node *mover = root;

    while (mover)
    {
        if (id == mover->id)
        {
            return mover;
        }
        else if (id > mover->id)
        {
            mover = mover->right;
        }
        else
        {
            mover = mover->left;
        }
    }
    cout << "Entry with the entered id not found\n";
    return nullptr;
}

void BST::deleteTree(Node *head)
{
    if (head)
    {
        deleteTree(head->left);
        deleteTree(head->right);
        delete head;
    }
}

BST::~BST()
{
    deleteTree(root);
    size = 0;
    root = nullptr;
}
