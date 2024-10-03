#include <bits/stdc++.h>

using namespace std;
//DONE
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
    void removeElements(int val)
    {
        Node *temp = head, *prev = NULL;
        if(temp->getData()==val){
            prev = head;
            head = head->getNext();
            temp = head;
            delete prev;
        }
        while (temp != NULL)
        {
            if (temp->getData() == val)
            {
                // Node *temp1 = temp;
                prev->setNext(temp->getNext());
                prev= temp->getNext();
                delete temp;
                temp = prev;
                // delete temp1;
            }
            else
            {
                prev = temp;
                temp = temp->getNext();
            }
        }
            displayLinkedList();
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
        cout << "Deleted" << endl;
    }
};

int main()
{
    int size = 8;
    int arr[size] = {3, 1, 2, 5, 8, 1, 3, 54};
    cout << "Printing array: " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SinglyLinkedList *list1 = new SinglyLinkedList();
    list1->turnArrToLL(arr, size);
    list1->displayLinkedList();
    list1->removeElements(1);
    list1->removeElements(3);
    list1->removeElements(2);

    return 0;
}