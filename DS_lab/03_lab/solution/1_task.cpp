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
    void setHead(Node *head)
    {
        this->head = head;
    }
    void setTail(Node *tail)
    {
        this->tail = tail;
    }
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void turnArrToLL(int arr[])
    {
        head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < 5; ++i)
        {
            Node *n = new Node(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        tail = temp;
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
        cout << "Displaying linkedList: " << endl;
        while (temp != NULL)
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
    ~SinglyLinkedList()
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
    int arr[5] = {3, 1, 2, 5, 8};
    cout << "Printing array: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SinglyLinkedList *list1 = new SinglyLinkedList();
    list1->turnArrToLL(arr);
    list1->displayLinkedList();
    list1->insertAtTail(9);
    list1->displayLinkedList();
    list1->insertAtPos(3, 11);
    list1->displayLinkedList();
    list1->insertAtFront(4);
    list1->displayLinkedList();
    cout << "Removing elements" << endl;
    list1->removeElements(1);
    list1->removeElements(2);
    list1->removeElements(5);
    list1->displayLinkedList();

    return 0;
}