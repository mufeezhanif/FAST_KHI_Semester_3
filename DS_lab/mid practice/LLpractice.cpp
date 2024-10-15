#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    };
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Singly
{
public:
    Node *head;
    Node *tail;
    int size;

    Singly()
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
    }

    void InsertAtFront(int val)
    {
        Node *newNode = new Node(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }
    void insertAtBack(int val)
    {
        Node *newNode = new Node(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = tail->next;
    }
    void deleteAtFront()
    {

        if (!head)
            return;
        --size;
        if (!head->next)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else
        {

            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void deleteAtLast()
    {
        if (!head)
            return;
        --size;
        if (head == tail)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        temp->next = nullptr;
    }
    void insertAtPos(int pos, int val)
    {
        // this will insert a new node which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        ++size;
        if (pos == 1)
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
            return;
        }
        int i = 1;
        Node *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        Node *newNode = new Node(val);
        Node *temp = mover->next;
        mover->next = newNode;
        newNode->next = temp;
    }
    void deleteAtPos(int pos)
    {
        // this will delete a node which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        --size;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int i = 1;
        Node *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        Node *temp = mover->next;
        mover->next = mover->next->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // bubble sort
    void bubbleSort()
    {
        Node *mover = head;
        bool swapped = true;
        while (swapped)
        {
            swapped = false;
            mover = head;
            while (mover && mover->next)
            {
                if (mover->data > mover->next->data)
                {
                    int data = mover->data;
                    mover->data = mover->next->data;
                    mover->next->data = data;
                    swapped = true;
                }
                mover = mover->next;
            }
        }
    }

    // selection sort
    void selectionSort()
    {
        
    }
};

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int data = 0)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class Doubly
{
public:
    DNode *head;
    DNode *tail;
    int size;

    Doubly()
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
    }

    void InsertAtFront(int val)
    {
        DNode *newNode = new DNode(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insertAtBack(int val)
    {
        DNode *newNode = new DNode(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
    void deleteAtFront()
    {

        if (!head)
            return;
        --size;
        if (!head->next)
        {
            DNode *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else
        {

            DNode *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    void deleteAtLast()
    {
        if (!head)
            return;
        --size;
        if (head == tail)
        {
            DNode *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        DNode *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    void insertAtPos(int pos, int val)
    {
        // this will insert a new DNode which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        if (pos == 1)
        {
            DNode *temp = new DNode(val);
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }
        if (pos == size)
        {
            DNode *newNode = new DNode(val);
            DNode *prev = tail->prev;
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = tail;
            tail->prev = newNode;
            ++size;
            return;
        }
        ++size;
        int i = 1;
        DNode *mover = head;
        while (i < pos)
        {
            mover = mover->next;
            ++i;
        }
        DNode *newDNode = new DNode(val);
        DNode *temp = mover->prev;
        temp->next = newDNode;
        newDNode->prev = temp;
        newDNode->next = mover;
        mover->prev = newDNode;
    }
    void deleteAtPos(int pos)
    {
        // this will delete a DNode which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        if (pos == 1)
        {
            DNode *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return;
        }
        if (pos == size)
        {
            DNode *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            --size;
            return;
        }
        --size;
        int i = 1;
        DNode *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        DNode *temp = mover->next;
        mover->next = mover->next->next;
        mover->next->prev = mover;
        delete temp;
    }
    void display()
    {
        DNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class SinglyCircular
{
public:
    Node *head;
    Node *tail;
    int size;

    SinglyCircular()
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
    }

    void InsertAtFront(int val)
    {
        Node *newNode = new Node(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    void insertAtBack(int val)
    {
        Node *newNode = new Node(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        tail->next = newNode;
        tail = tail->next;
        tail->next = head;
    }
    void deleteAtFront()
    {

        if (!head)
            return;
        if (size == 1)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else
        {

            Node *temp = head;
            head = head->next;
            tail->next = head;

            delete temp;
        }
        --size;
    }
    void deleteAtLast()
    {
        if (!head)
            return;
        if (size == 1)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = head;
        }
        --size;
    }
    void insertAtPos(int pos, int val)
    {
        // this will insert a new node which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        ++size;
        if (pos == 1)
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
            return;
        }
        int i = 1;
        Node *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        Node *newNode = new Node(val);
        Node *temp = mover->next;
        mover->next = newNode;
        newNode->next = temp;
    }
    void deleteAtPos(int pos)
    {
        // this will delete a node which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        --size;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int i = 1;
        Node *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        Node *temp = mover->next;
        mover->next = mover->next->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class DoublyCircular
{
public:
    DNode *head;
    DNode *tail;
    int size;

    DoublyCircular()
    {
        head = nullptr;
        size = 0;
        tail = nullptr;
    }

    void InsertAtFront(int val)
    {
        DNode *newNode = new DNode(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;
            head->prev = tail;
            tail->next = head;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        tail->next = head;
        head->prev = tail;
    }
    void insertAtBack(int val)
    {
        DNode *newNode = new DNode(val);
        ++size;
        if (!head)
        {
            head = newNode;
            tail = newNode;

            tail->next = head;
            head->prev = tail;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;

        tail->next = head;
        head->prev = tail;
    }
    void deleteAtFront()
    {

        if (!head)
            return;
        --size;
        if (head == tail)
        {
            DNode *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        else
        {
            DNode *temp = head;
            head = head->next;

            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
    void deleteAtLast()
    {
        if (!head)
            return;
        --size;
        if (head == tail)
        {
            DNode *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }
        DNode *temp = tail;
        tail = tail->prev;

        tail->next = head;
        head->prev = tail;
        delete temp;
    }
    void insertAtPos(int pos, int val)
    {
        // this will insert a new DNode which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        if (pos == 1)
        {
            DNode *temp = new DNode(val);
            temp->next = head;
            head->prev = temp;
            head = temp;

            tail->next = head;
            head->prev = tail;
            return;
        }
        if (pos == size)
        {
            DNode *newNode = new DNode(val);
            DNode *prev = tail->prev;
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = tail;
            tail->prev = newNode;
            ++size;
            return;
        }
        ++size;
        int i = 1;
        DNode *mover = head;
        while (i < pos)
        {
            mover = mover->next;
            ++i;
        }
        DNode *newDNode = new DNode(val);
        DNode *temp = mover->prev;
        temp->next = newDNode;
        newDNode->prev = temp;
        newDNode->next = mover;
        mover->prev = newDNode;
    }
    void deleteAtPos(int pos)
    {
        // this will delete a DNode which will be on the position entered
        if (pos > size)
        {
            cout << "Invalid size entered" << endl;
            return;
        }
        if (pos == 1)
        {
            DNode *temp = head;
            head = head->next;

            tail->next = head;
            head->prev = tail;
            delete temp;
            return;
        }
        if (pos == size)
        {
            DNode *temp = tail;
            tail = tail->prev;

            tail->next = head;
            head->prev = tail;
            delete temp;
            --size;
            return;
        }
        --size;
        int i = 1;
        DNode *mover = head;
        while (i < pos - 1)
        {
            mover = mover->next;
            ++i;
        }
        DNode *temp = mover->next;
        mover->next = mover->next->next;
        mover->next->prev = mover;
        delete temp;
    }
    void display()
    {
        DNode *temp = head;
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    return 0;
}