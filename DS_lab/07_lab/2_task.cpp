#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data)
    {
        next = NULL;
    }
    Node()
    {
        next = NULL;
        data = 0;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addElement(int data)
    {
        if (!head)
        {
            head = new Node(data);
            tail = head;
            ++size;
            return;
        }
        tail->next = new Node(data);
        tail = tail->next;
        ++size;
    }

    void removeDuplicates()
    {
        Node *temp = head;
        while (temp->next)
        {
            if (temp->data == temp->next->data)
            {

                Node *curr = temp->next;
                temp->next = temp->next->next;
                delete curr;
            }
            else{

            temp = temp->next;
            }
        }
    }

    void displayList()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList l1;
    l1.addElement(2);
    l1.addElement(2);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(4);
    l1.addElement(5);
    l1.displayList();
    l1.removeDuplicates();
    l1.displayList();
    return 0;
}