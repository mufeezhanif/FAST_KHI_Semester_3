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
    void setHead(Node *head)
    {
        this->head = head;
    }
    void setTail(Node *tail)
    {
        this->tail = tail;
    }
    void turnArrToLL(int *arr, int size)
    {
        head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < size; ++i)
        {
            Node *n = new Node(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        delete arr;
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
    void sortEvenFirst()
    {
        Node *evenHead = nullptr;
        Node *oddHead = nullptr;
        Node *evenTail = nullptr;
        Node *oddTail = nullptr;
        if (head == NULL || head->getNext() == NULL)
        {
            return;
        }
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->getData() % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = evenTail = curr;
                }
                else
                {
                    evenTail->setNext(curr);
                    evenTail = evenTail->getNext();
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = oddTail = curr;
                }
                else
                {
                    oddTail->setNext(curr);
                    oddTail = oddTail->getNext();
                }
            }
            curr = curr->getNext();
        }
        if (evenHead == NULL)
        {
            head = oddHead;
        }
        if (evenTail)
            evenTail->setNext(nullptr);
        if (oddTail)
            oddTail->setNext(nullptr);

        evenTail->setNext(oddHead);
        head = evenHead;
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
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
    cout << "Displaying entered array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    SinglyLinkedList *l1 = new SinglyLinkedList();
    l1->turnArrToLL(arr, size);
    l1->sortEvenFirst();
    l1->displayLinkedList();
    return 0;
}