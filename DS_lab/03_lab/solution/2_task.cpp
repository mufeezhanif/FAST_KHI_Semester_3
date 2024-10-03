#include <bits/stdc++.h>

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
    void setHead(Node *head)
    {
        this->head = head;
    }
    void setTail(Node *tail)
    {
        this->tail = tail;
    }
    void turnArrToLL(int arr[], int size)
    {
        head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < size; ++i)
        {
            Node *n = new Node(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        tail = temp;
    }
    void rotateList(int n)
    {
        // considering that n is less than the length of linked list
        int i = 0;
        Node *temp = head;
        while (i < n - 1)
        {
            temp = temp->getNext();
            i++;
        }
        Node *temp1 = head;
        head = temp->getNext();
        temp->setNext(NULL);
        tail->setNext(temp1);
        tail = temp;
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
    }
};

int main()
{
    int arr[] = {5, 3, 1, 8, 6, 4, 2};
    int size = 6;
    int n;
    SinglyLinkedList *ptr = new SinglyLinkedList();
    ptr->turnArrToLL(arr, size);
    ptr->displayLinkedList();
    cout<<"Enter no of rotation: ";
    cin >> n;
    ptr->rotateList(n);
    ptr->displayLinkedList();
    return 0;
}