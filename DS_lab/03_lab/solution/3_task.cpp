#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node()
    {
        next = NULL;
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
    Node<T> *listHead;
    Node<T> *listTail;
    SinglyLinkedList<T> *flightHead;
    SinglyLinkedList<T> *flightNext;

    SinglyLinkedList<T> *flightTail;
    SinglyLinkedList<T> *passengers;
    int N; // no of flights

public:
    SinglyLinkedList()
    {
        listHead = NULL;
        listTail = NULL;
        flightHead = NULL;
        flightTail = NULL;
        passengers = NULL;
        flightNext = NULL;
        N = 0;
    }
    void addNewFlight()
    {
        SinglyLinkedList<T> *n = new SinglyLinkedList<T>();

        SinglyLinkedList<T> *mover;
        if (flightHead == NULL)
        {
            flightHead = n;
            flightTail = n;
        }
        else
        {
            mover = flightHead;
            while (mover->flightNext != NULL)
            {
                mover = mover->flightNext;
            }
            mover->flightNext = n;
            flightTail = n;
        }
        ++N;
        cout << "New flight added" << N << endl;
    }
    void reserveTicket(int n)
    {

        if (n > N)
        {
            cout << "flight of this number doesn't exist" << endl;
            return;
        }
        SinglyLinkedList<T> *mover = flightHead;
        if (n != 1)
            while (n--)
            {
                mover = mover->flightNext;
            }

        string name;
        cout << "Enter Name: " << endl;
        getline(cin, name);
        Node<T> *newNode = new Node<T>(name);
        cout << name << endl;
        if (passengers == NULL)
        {
            passengers = new SinglyLinkedList<T>();
            passengers->listHead = newNode;
            passengers->listTail = newNode;
            cout << name << endl;
        }
        else
        {
            cout << name << endl;
            passengers->listTail->setNext(newNode);
            passengers->listTail = passengers->listTail->getNext();
        }
        cout << "Passenger added successfully" << endl;
    }
    bool checkSeat(T val)
    {

        // assuming that user will enter the correct flight number
        cout << "Enter flight number: ";
        int n;
        cin >> n;
        if (n > N)
        {
            cout << "This number of flight does not exist" << endl;
            return false;
        }
        SinglyLinkedList<T> *mover = flightHead;
        if (n != 1)
            while (n--)
            {
                mover = mover->flightNext;
            }

        if (mover->passengers->listHead == NULL)
        {
            cout << "passenger not found" << endl;
            return false;
        }
        else
        {
            Node<T> *listMover = mover->passengers->listHead;
            while (listMover->next != NULL)
            {
                if (listMover->data == val)
                {
                    cout << "passenger found " << endl;
                    return true;
                }
                listMover = listMover->next;
            }
            return false;
        }
    }
    void displaySystem()
    {
        SinglyLinkedList<T> *mover = flightHead;
        while (mover != NULL)
        {
            cout << "\tDisplaying next flight passengers: " << endl;
            mover->displayPeople(mover);
            mover = mover->flightNext;
        }
    }
    void displayPeople(SinglyLinkedList<T> *temp)
    {
        Node<T> *mover = temp->passengers->listHead;
        cout << "\t\tDisplaying Passengers of current flight: " << endl;
        while (mover != NULL)
        {
            cout << mover->data << " ";
            mover = mover->next;
        }
        cout << endl;
    }
    void cancelSeat(T val)
    {
        int n;
        cout << "Enter you flight number: ";
        cin >> n;

        SinglyLinkedList<T> *mover = flightHead;
        if (mover == NULL)
            return;
        if (n != 1)
            while (n--)
            {
                mover = mover->flightNext;
            }

        Node<T> *temp = mover->passengers->listHead;
        if (temp == NULL)
        {
            cout << "No passengers in this flight" << endl;
            return;
        }
        while (temp->getNext()->getData() != val && temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        Node<T> *temp1 = temp->getNext();
        temp->setNext(temp->getNext()->getNext());
        delete temp1;
        cout << "Passenger's seat has been cancelled" << endl;
    }
};

int main()
{
    SinglyLinkedList<string> *system1 = new SinglyLinkedList<string>();
    system1->addNewFlight();
    system1->reserveTicket(1);
    system1->reserveTicket(1);
    return 0;
}