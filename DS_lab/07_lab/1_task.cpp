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
    // Node *reverse(Node *temp, int m, int n)
    // {
    //     if (!temp)
    //     {
    //         return NULL;
    //     }
    //     int loop = m - n;
    //     int i = 0;
    //     Node * temp2 = temp;
    //     Node *prev = NULL;
    //     Node * next = NULL;
    //     while (i < loop)
    //     { // won't check if temp, becuase i have verified the size and m , n
    //         ++i;
    //         next = temp2->next;
    //         temp2->next = prev;
    //         prev = temp2;
    //         temp2 = next;
    //     }
    //     return prev;
    // }
    // void reverseFromPositions(int m, int n)
    // {
    //     if (!head)
    //         return;
    //     if (m > size || n > size)
    //     {
    //         cout << "Linked list is not much populated" << endl;
    //         return;
    //     }
    //     int i = 0;
    //     Node *temp = head;
    //     Node *prev = NULL;
    //     while (i < m - 1)
    //     {
    //         i++;
    //         prev = temp;
    //         temp = temp->next;
    //     }
    //     Node *temp2 = temp;
    //     Node *last = temp;

    //     while (i < n - 1)
    //     {
    //         i++;
    //         last = temp;
    //         temp2 = temp2->next;
    //     }
    //     prev->next = reverse(temp, m, n);

    //     while (prev->next)
    //     {
    //         prev = prev->next;
    //     }
    //     prev->next = last;
    // }
    
    
    void reverse(int a, int b)
    {
        if (a == b)
            return;

        Node *prevBefore = nullptr;
        Node *curr = head;

        for (int i = 1; i < a && curr != nullptr; i++)
        {
            prevBefore = curr;
            curr = curr->next;
        }

        Node *lastReversed = curr;
        Node *prev = nullptr;

        while (curr != nullptr && a <= b)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            a++;
        }

        if (prevBefore != nullptr)
        {
            prevBefore->next = prev;
        }
        else
        {
            head = prev; 
        }

        lastReversed->next = curr;
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
    l1.addElement(10);
    l1.addElement(20);
    l1.addElement(30);
    l1.addElement(40);
    l1.addElement(50);
    l1.addElement(60);
    l1.addElement(70);
    l1.reverse(3,6);
    l1.displayList();
    return 0;
}