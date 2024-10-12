#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext()
    {
        return next;
    }
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }
};

class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->setNext(head);
            head = n;
        }
    }
    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->setNext(n);
            tail = tail->getNext();
        }
    }
    void displayLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }
    void deleteLinkedList()
    {
        Node *temp = head;
        Node *n;
        while (temp != NULL)
        {
            n = temp;
            temp = temp->getNext();
            delete n;
        }
    }
    ~SinglyLinkedList()
    {
        deleteLinkedList();
        cout << "Deleted" << endl;
    }
};

signed main()
{
    SinglyLinkedList *list1 = new SinglyLinkedList();
    list1->insertAtFront(5);
    list1->insertAtTail(1);
    list1->insertAtTail(3);
    list1->displayLinkedList();

    return 0;
}