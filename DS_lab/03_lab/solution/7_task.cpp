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

class circularList
{
private:
    Node *head;
    Node *tail;

public:
   
    circularList()
    {
        head = NULL;
        tail = NULL;
    }
    void setHead(Node *head)
    {
        this->head = head;
    }
    void setTail(Node *tail)
    {
        this->tail = tail;
    }
    void turnArrToLL(int arr[])
    {
        head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < 7; ++i)
        {
            Node *n = new Node(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        tail = temp;
        tail->setNext(head);
    }

    void insertAtFront(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->setNext(head);
        }
        else
        {
            n->setNext(head);
            head = n;
            tail->setNext(head);
        }
    }
    void removeElements(int val)
    {
        Node *temp = head;
        while (temp->getNext()->getData() != val)
        {
            temp = temp->getNext();
        }
        Node *temp1 = temp->getNext();
        temp->setNext(temp->getNext()->getNext());
        delete temp1;
    }
    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->setNext(head);
        }
        else
        {
            tail->setNext(n);
            tail = tail->getNext();
            tail->setNext(head);
        }
    }
    void displayLinkedList()
    {
        Node *temp = head;
        cout << "Displaying linkedList: " << endl;
        while (temp->getNext() != head)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
    void insertAtPos(int pos, int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
            tail = n;
            tail->setNext(head);
        }
        else
        {
            int i = 1;
            Node *temp = head;
            while (i != pos - 1)
            {
                temp = temp->getNext();
                ++i;
            }
            n->setNext(temp->getNext());
            temp->setNext(n);
        }
    }
    
    ~circularList()
    {
        Node *temp = head;
        Node *n;
        while (temp != NULL)
        {
            n = temp;
            temp = temp->getNext();
            delete n;
        }
        cout << "Deleted" << endl;
    }
};

int main()
{
    circularList *cl = new circularList();
    int arr[] = {34,4,2,55,343,25,543};
    cl->turnArrToLL(arr);
    cl->insertAtTail(43);
    cl->insertAtFront(3);
    cl->insertAtPos(3,989);
    cl->removeElements(55);
    cl->displayLinkedList();
    return 0;
}