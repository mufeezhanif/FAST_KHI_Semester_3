#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class stNode
{
public:
    Node *data;
    stNode *next;
    stNode(Node *ref)
    {
        data = ref;
        next = nullptr;
    }
};
class Stack
{
public:
    stNode *head;
    Stack() : head(nullptr) {};

    void push(Node *ptr)
    {
        stNode *newNode = new stNode(ptr);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    Node *pop()
    {
        if (!head)
        {
            return nullptr;
        }
        Node *temp = head->data;
        head = head->next;
        return temp;
    }
    Node *peek()
    {
        if (!head)
        {
            return nullptr;
        }
        Node *temp = head->data;
        return temp;
    }

    bool isEmpty()
    {
        return head ? true : false;
    }
};

class Heap
{
public:
    int size;
    Node *root;
    Heap()
    {
        root = nullptr;
        size = 0;
    }

    void insert(int val)
    {
        if (!root)
        {
            root = new Node(val);
            return;
        }
        addNewNode(root, val);
    }
    void addNewNode(Node *head, int val)
    {
        Stack st;
        if (!head->left || !head->right)
        {
            Node *temp = (head->left) ? head->left : head->right;

            if(temp== head->left){
                head->left = new Node(val);
            }
            else{
                head->right = new Node(val);
            }
            return;
        }
        st.push(head->right);
        st.push(head->left);
        while(!st.isEmpty()){
            Node * temp = st.pop();
            
        }

    }
};

int main()
{

    return 0;
}