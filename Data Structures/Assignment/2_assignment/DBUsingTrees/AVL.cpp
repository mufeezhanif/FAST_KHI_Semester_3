#include "AVL.h"

AVL::AVL()
{
    root = nullptr;
    size = 0;
}

void AVL::insertData(int id, string name, int age)
{
    Node *newNode = new Node(id, name, age);
    ++size;
    if (!root)
    {
        root = newNode;
    }
    else
    {
        root = insert(root, newNode);
    }
}

Node *AVL::insert(Node *head, Node *newNode)
{
    if (!head)
        return newNode;

    if (head->id > newNode->id)
    {
        head->left = insert(head->left, newNode);
    }
    else if (head->id < newNode->id)
    {
        head->right = insert(head->right, newNode);
    }
    else
    {
        return head;
    }

    head->height = 1 + max(getHeight(head->left), getHeight(head->right));
    int balance = getBalance(head);

    if (balance > 1 && newNode->id < head->left->id)
        return rightRotate(head);

    if (balance < -1 && newNode->id > head->right->id)
        return leftRotate(head);

    if (balance > 1 && newNode->id > head->left->id)
    {
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }

    if (balance < -1 && newNode->id < head->right->id)
    {
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }

    return head;
}

int AVL::getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

int AVL::getHeight(Node *node)
{
    return node ? node->height : 0;
}

Node *AVL::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *AVL::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T = x->right;

    x->right = y;
    y->left = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

Node *AVL::minValNode(Node *node)
{
    Node *current = node;
    while (current->left)
        current = current->left;
    return current;
}

void AVL::DeleteEntry(int id)
{
    if (!root)
    {
        cout << "No entry in the tree\n";
        return;
    }
    root = deleteNode(root, id);
}

Node *AVL::deleteNode(Node *node, int id)
{
    if (!node)
        return node;

    if (id < node->id)
    {
        node->left = deleteNode(node->left, id);
    }
    else if (id > node->id)
    {
        node->right = deleteNode(node->right, id);
    }
    else
    {
        if (!node->left || !node->right)
        {
            Node *temp = node->left ? node->left : node->right;
            if (!temp)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp; 
            }
            delete temp;
        }
        else
        {
            Node *temp = minValNode(node->right);
            node->copyObj(temp);
            node->right = deleteNode(node->right, temp->id);
        }
    }

    if (!node)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *AVL::search(int id)
{
    if (!root)
    {
        cout << "No entry in the tree\n";
        return nullptr;
    }

    Node *mover = root;
    while (mover)
    {
        if (mover->id > id)
            mover = mover->left;
        else if (mover->id < id)
            mover = mover->right;
        else
        {
            return mover;
        }
    }
    cout << "Entry with the entered ID not found\n";
    return nullptr;
}

void AVL::printTable()
{
    cout << "Printing the table of the tree: \n";
    preOrder(root);
}

void AVL::preOrder(Node *node)
{
    if (!node)
        return;
    preOrder(node->left);
    node->printData();
    preOrder(node->right);
}

void AVL::deleteTree(Node *head)
{
    if (head)
    {
        deleteTree(head->left);
        deleteTree(head->right);
        delete head;
    }
}

AVL::~AVL()
{
    deleteTree(root);
}
