#include <bits/stdc++.h>

using namespace std;
class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext()
    {
        return next;
    }
    void setPrev(Node *prev)
    {
        this->prev = prev;
    }
    Node *getPrev()
    {
        return prev;
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

class DoublyLinkedList
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
    Node *getHead()
    {
        return head;
    }
    Node *getTail()
    {
        return tail;
    }
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void turnArrToLL(int arr[], int size)
    {
        head = new Node(arr[0]);
        Node *temp = head;

        Node *prev = NULL;
        for (int i = 1; i < size; ++i)
        {
            Node *n = new Node(arr[i]);
            temp->setNext(n);
            temp->setPrev(prev);
            prev = temp;
            temp = temp->getNext();
        }
        tail = temp;
        displayLinkedList();
    }
    DoublyLinkedList *concatenateLL(DoublyLinkedList *M)
    {
        if (M == NULL)
        {
            return this;
        }
        Node *Mhead = M->getHead();
        Node *Mtail = M->getTail();
        Node *lmover = head;
        Node *Mmover = Mhead;
        while (Mmover != NULL)
        {
            int val = Mmover->getData();
            Node *n = new Node(val), *prev = NULL;
            if (head == NULL)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->setNext(n);
                prev = tail;
                tail = tail->getNext();
                tail->setPrev(prev);
            }
            Mmover = Mmover->getNext();
        }
        return this;
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
    ~DoublyLinkedList()
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
    DoublyLinkedList *L = new DoublyLinkedList();
    DoublyLinkedList *M = new DoublyLinkedList();
    int arr[] = {1, 2, 3, 4, 5};
    int arr1[] = {6, 7, 8, 9, 3434};
    L->turnArrToLL(arr, 5);
    M->turnArrToLL(arr1, 5);
    L->concatenateLL(M);
    L->displayLinkedList();
    return 0;
}