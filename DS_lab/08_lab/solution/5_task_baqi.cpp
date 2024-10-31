#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data)
    {
        next = nullptr;
    }
};
class LL
{
public:
    Node *head;
    Node *tail;
    LL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void AddNewNode(int val)
    {
        if (!head)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
    void displayLL()
    {
        Node *mover = head;
        cout << "Displaying Linked List:\n";
        while (mover)
        {
            cout << mover->data << " ";
            mover = mover->next;
        }
        cout << endl;
    }
    void swapNodes(Node *n1, Node *n2)
    {
        if (n1 == n2 || !n1 || !n2)
            return;
        Node *mover = head;
        Node *mover1 = head;

        while (mover->next && mover->next != n1)
        {
            mover = mover->next;
        }
        while (mover1->next && mover1->next != n2)
        {
            mover1 = mover1->next;
        }

        if (mover->next && mover1->next)
        {
            Node *next1 = n2->next;
            mover->next = n2;
            n2->next = n1->next;
            mover1->next = n1;
            n1->next = next1;
        }
    }

    void quick_sort()
    {
        head = quickSortCal(head);
    }

    Node *quickSort()
    {
        if (!head || !head->next)
            return head;

        Node *pivot = tail; // First Node as Pivot
        Node *lessHead = nullptr;
        Node *lessTail = nullptr;
        Node *greaterHead = nullptr;
        Node *greaterTail = nullptr;

        Node *current = node->next;

        // Partitioning the List into less and greater parts relative to pivot
        while (current)
        {
            if (current->data < pivot->data)
            {
                if (!lessHead)
                {
                    lessHead = current;
                    lessTail = current;
                }
                else
                {
                    lessTail->next = current;
                    lessTail = current;
                }
            }
            else
            {
                if (!greaterHead)
                {
                    greaterHead = current;
                    greaterTail = current;
                }
                else
                {
                    greaterTail->next = current;
                    greaterTail = current;
                }
            }
            current = current->next;
        }

        if (lessTail)
            lessTail->next = nullptr; // Terminate Less List
        if (greaterTail)
            greaterTail->next = nullptr; // Terminate Greater List

        lessHead = quickSortCal(lessHead);
        greaterHead = quickSortCal(greaterHead);

        // Combine the lists
        pivot->next = nullptr;

        if (!lessHead)
        {                              // If the less list is empty, pivot is the head
            pivot->next = greaterHead; // Append greater list after pivot
            return pivot;
        }

        lessTail = lessHead;
        while (lessTail->next)
        {
            lessTail = lessTail->next; // Traverse till the end of less
        }

        lessTail->next = pivot;    // Append Pivot to the end of less
        pivot->next = greaterHead; // Append greater list after pivot

        return lessHead; // Return the new head of sorted list
    }
};
int main()
{
    return 0;
}