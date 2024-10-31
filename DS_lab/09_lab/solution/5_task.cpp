#include <bits/stdc++.h>
using namespace std;
class NodeForLL
{
public:
    NodeForLL *next;
    int data;
    NodeForLL(int val) : data(val)
    {
        next = nullptr;
    }
};

class LL
{
public:
    NodeForLL *head;
    NodeForLL *tail;
    int size;
    LL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void insertion(int val)
    {
        NodeForLL *newNode = new NodeForLL(val);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        ++size;
    }
    NodeForLL *findMed()
    {
        NodeForLL *slow = head;
        NodeForLL *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
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

    double findMedian()
    {
        LL l1;
        copyToLinkedList(root, l1);
        int count = l1.size;
        if (count % 2 != 0)
        {
            NodeForLL *temp = l1.findMed();
            return temp->data;
        }
        else
        {
            int med = count / 2;
            NodeForLL *mover = l1.head;
            int i = 1;
            while (mover && i < med)
            {
                mover = mover->next;
                ++i;
            }

            return ((mover->data + mover->next->data) / 2);
        }
    }
    void copyToLinkedList(Node *temp, LL &l1)
    {
        if (!temp)
        {
            // cout<<"No element in the tree"<<endl;
            return;
        }
        copyToLinkedList(temp->left, l1);
        l1.insertion(temp->val);
        copyToLinkedList(temp->right, l1);
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
int main()
{
    BST b1;
    b1.insertion(45);
    b1.insertion(4);
    b1.insertion(5);
    b1.insertion(15);
    b1.insertion(25);
    b1.insertion(2);
    b1.inOrder();
    cout << "Median: " << b1.findMedian()<<endl;
    return 0;
}