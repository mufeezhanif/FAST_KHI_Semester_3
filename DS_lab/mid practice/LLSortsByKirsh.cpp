#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtHead(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        if (tail == nullptr)
        {
            tail = newnode;
        }
    }

    int getLength()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void insertAtPos(int pos, int val)
    {
        if (pos == 1)
        {
            insertAtHead(val);
            return;
        }

        if (pos == getLength() + 1)
        {
            insertAtEnd(val);
            return;
        }

        if (pos > getLength() + 1)
        {
            cout << "POS OUT OF BOUNDS " << endl;
            return;
        }

        Node *newnode = new Node(val);
        Node *temp = head;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteHead()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void deleteTail()
    {
        if (head == nullptr)
            return;

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void deletePos(int pos)
    {
        if (pos == 1)
        {
            deleteHead();
            return;
        }

        if (pos == getLength())
        {
            deleteTail();
            return;
        }

        if (pos > getLength())
        {
            cout << "POS OUT OF BOUNDS" << endl;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        if (temp->next == nullptr)
        { // If deleting last node
            tail = prev;
        }
        delete temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Bubble Sort
    void bubble_sort()
    {
        bool swapped;
        if (head)
        {
            do
            {
                swapped = false;
                Node *curr = head;

                while (curr && curr->next)
                {
                    if (curr->data > curr->next->data)
                    {
                        int temp = curr->data;
                        curr->data = curr->next->data;
                        curr->next->data = temp;
                        swapped = true;
                    }
                    curr = curr->next;
                }

            } while (swapped);
        }
    }

    // Selection Sort
    void selection_sort()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *curr = head;

        while (curr)
        {
            Node *minNode = curr;
            Node *temp = curr->next;

            while (temp)
            {
                if (temp->data < minNode->data)
                {
                    minNode = temp;
                }
                temp = temp->next;
            }

            if (minNode != curr)
            {
                int t = minNode->data;
                minNode->data = curr->data;
                curr->data = t;
            }
            curr = curr->next;
        }
    }

    void insertion_sort()
    {
        Node *sorted = nullptr; // new link List to store sorted List
        Node *curr = head;

        while (curr)
        {
            Node *nextNode = curr->next;
            // If the sorted list is empty or the current node data is smaller then the sorted "head" data then place it at the beginning
            if (sorted == nullptr || curr->data <= sorted->data)
            {
                curr->next = sorted;
                sorted = curr;
            }
            else
            {
                // find the correct place
                Node *temp = sorted;
                while (temp->next && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }

            curr = nextNode;
        }

        head = sorted;
    }

    // BINARY SEARCH ON LINKEDLIST
    Node *getNodeAtIndex(int mid)
    {
        Node *temp = head;
        for (int i = 0; i < mid && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool binary_search(int val)
    {

        int low = 0;
        int high = getLength() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            Node *middleNode = getNodeAtIndex(mid);
            if (middleNode == nullptr)
            {
                return false;
            }
            else if (middleNode->data == val)
            {
                return true;
            }
            else if (middleNode->data < val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }

    bool interpolation_search(int val)
    {
        int left = 0;
        int right = getLength() - 1;

        while (left <= right)
        {
            Node *lower = getNodeAtIndex(left);  // arr[left]
            Node *upper = getNodeAtIndex(right); // arr[right]

            if (lower == nullptr || upper == nullptr)
                return false;

            if (val < lower->data || val > upper->data) // out of bound
                return false;

            if (lower->data == upper->data) // division by zero case
            {
                if (lower->data == val)
                    return true;

                return false;
            }

            // Interpolation formula
            int pos = left + ((val - lower->data) * (right - left) / (upper->data - lower->data));

            Node *nodeAtPos = getNodeAtIndex(pos);

            if (nodeAtPos == nullptr)
                return false;

            if (nodeAtPos->data == val)
            {
                return true;
            }
            else if (nodeAtPos->data < val)
            {
                left = pos + 1;
            }
            else
            {
                right = pos - 1;
            }
        }
        return false;
    }

    // MERGE SORT
    void merge_sort()
    {
        head = mergeSortCal(head);
    }

    Node *getMiddle(Node *node)
    {
        if (!node)
            return node;

        Node *slow = node;
        Node *fast = node->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *merge(Node *leftList, Node *rightList)
    {

        if (!leftList)
            return rightList;
        if (!rightList)
            return leftList;

        Node *dummy = new Node(-1);
        Node *temp1 = leftList;
        Node *temp2 = rightList;
        Node *current = dummy;

        while (temp1 && temp2)
        {
            if (temp1->data < temp2->data)
            {
                current->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                current->next = temp2;
                temp2 = temp2->next;
            }
            current = current->next;
        }

        if (temp1)
            current->next = temp1;
        else
            current->next = temp2;

        Node *merge = dummy->next;
        delete dummy;

        return merge;
    }

    Node *mergeSortCal(Node *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;

        Node *middleNode = getMiddle(node);
        Node *leftList = node;
        Node *rightList = middleNode->next;

        middleNode->next = nullptr; // splitting the List into two halves

        leftList = mergeSortCal(leftList);
        rightList = mergeSortCal(rightList);

        return merge(leftList, rightList);
    }

    // QUICK SORT
    void quick_sort()
    {
        head = quickSortCal(head);
    }

    Node *quickSortCal(Node *node)
    {
        if (!node || !node->next)
            return node;

        Node *pivot = node; // First Node as Pivot
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
    LinkedList l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(2);
    l1.insertAtEnd(0);
    l1.insertAtEnd(3);
    l1.insertAtEnd(9);
    l1.insertAtEnd(1);

    l1.display();
    l1.quick_sort();

    l1.display();

    return 0;
}
