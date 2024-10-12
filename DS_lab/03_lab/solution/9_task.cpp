#include <iostream>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    void setNext(Node<T> *next)
    {
        this->next = next;
    }
    Node<T> *getNext()
    {
        return next;
    }
    T getData()
    {
        return data;
    }
    void setData(T data)
    {
        this->data = data;
    }
};
template <typename T>
class SinglyLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void setHead(Node<T> *head)
    {
        this->head = head;
    }
    void setTail(Node<T> *tail)
    {
        this->tail = tail;
    }
    Node<T> *getHead()
    {
        return head;
    }
    Node<T> *getTail()
    {
        return tail;
    }
    void turnArrToLL(int arr[], int size)
    {
        head = new Node<T>(arr[0]);
        Node<T> *temp = head;
        for (int i = 1; i < size; ++i)
        {
            Node<T> *n = new Node<T>(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        tail = temp;
        displayLinkedList();
    }
    void displayLinkedList(Node<T> *newHead = NULL)
    {
        if (newHead != NULL)
        {
            Node<T> *temp = newHead;
            cout << "Displaying linkedList: " << endl;
            while (temp != NULL)
            {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
        else
        {

            Node<T> *temp = head;
            cout << "Displaying linkedList: " << endl;
            while (temp != NULL)
            {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }
    void alernateNodes()
    {
        Node<T> *mover = head, *tempHead = head->getNext(), *alternate = tempHead, *prev = NULL;

        while (alternate != NULL && alternate->getNext() != NULL)
        {
            mover->setNext(alternate->getNext());
            mover = mover->getNext();
            alternate->setNext(mover->getNext());
            alternate = alternate->getNext();
        }

        alternate = tempHead;
        while (alternate != NULL)
        {
            Node<T> *next = alternate->getNext();
            alternate->setNext(prev);
            prev = alternate;
            alternate = next;
        }
        mover->setNext(prev);
        displayLinkedList();
    }
    ~SinglyLinkedList()
    {
        Node<T> *temp = head;
        Node<T> *n;
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
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    int size = 8;
    SinglyLinkedList<int> *list = new SinglyLinkedList<int>();
    list->turnArrToLL(arr, size);
    list->alernateNodes();
    return 0;
}