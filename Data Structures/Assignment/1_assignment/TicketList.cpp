#include "TicketList.h"

Node::Node(int ticketID, string customerName, int Priority, string serviceRequestDescription, string creationTime)
{
    next = nullptr;
    data = new Ticket(ticketID, customerName, Priority, serviceRequestDescription, creationTime);
}

TicketList::TicketList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
    ifstream configFile("config.txt");
    if (!configFile)
    {
        sortType = "quick";
    }
    else
    {
        getline(configFile, sortType);
    }
}

string TicketList::getCurrentTime()
{
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&time);
    ostringstream timeStream;
    timeStream << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return timeStream.str();
}

void TicketList::addATicket(int ticketID, string customerName, int Priority, string serviceRequestDescription)
{
    string currTime = getCurrentTime();
    if (!head)
    {
        head = new Node(ticketID, customerName, Priority, serviceRequestDescription, currTime);
        tail = head;
        ++size;
    }
    else
    {
        tail->next = new Node(ticketID, customerName, Priority, serviceRequestDescription, currTime);
        tail = tail->next;
        ++size;
        sortTickets();
    }
}

void TicketList::sortTickets()
{
    if (size > 100)
    {
        quickSort();
        cout << "Tickets sorted using Quick Sort.\n";
        return;
    }
    if (sortType == "bubble")
    {
        bubble_sort();
        cout << "Tickets sorted using Bubble Sort.\n";
    }
    else if (sortType == "selection")
    {
        selection_sort();
        cout << "Tickets sorted using Selection Sort.\n";
    }
    else if (sortType == "insertion")
    {
        insertion_sort();
        cout << "Tickets sorted using Insertion Sort.\n";
    }
    else if (sortType == "merge")
    {
        mergeSort();
        cout << "Tickets sorted using Merge Sort.\n";
    }
    else if (sortType == "quick")
    {
        quickSort();
        cout << "Tickets sorted using Quick Sort.\n";
    }
    else
    {
        cout << "Invalid sort type! Please choose from bubble, selection, insertion, merge, or quick.\n";
    }
}

void TicketList::bubble_sort()
{
    if (!head)
        return;
    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data->Priority > ptr1->next->data->Priority)
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Selection Sort Implementation
void TicketList::selection_sort()
{
    Node *start = head;
    while (start)
    {
        Node *minNode = start;
        Node *nextNode = start->next;
        while (nextNode)
        {
            if (nextNode->data->Priority < minNode->data->Priority)
            {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }
        if (minNode != start)
        {
            swap(start->data, minNode->data);
        }
        start = start->next;
    }
}

// Insertion Sort Implementation
void TicketList::insertion_sort()
{
    if (!head || !head->next)
        return;

    Node *sorted = nullptr;
    Node *current = head;

    while (current)
    {
        Node *next = current->next;

        if (!sorted || sorted->data->Priority >= current->data->Priority)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next && temp->next->data->Priority < current->data->Priority)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}
Node *TicketList::split(Node *mover)
{
    Node *fast = mover, *slow = mover;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node *TicketList::merge(Node *first, Node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data->Priority < second->data->Priority)
    {
        first->next = merge(first->next, second);
        first->next->next = nullptr;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->next = nullptr;
        return second;
    }
}

Node *TicketList::MergeSort(Node *mover)
{
    if (!mover || !mover->next)
        return mover;

    Node *second = split(mover);
    mover = MergeSort(mover);
    second = MergeSort(second);

    return merge(mover, second);
}

void TicketList::mergeSort()
{
    head = MergeSort(head);
}

// Quick Sort Implementation
Node *TicketList::partition(Node *start, Node *end)
{
    int pivot = end->data->Priority;
    Node *pivotPrev = start;
    Node *curr = start;

    while (start != end)
    {
        if (start->data->Priority < pivot)
        {
            swap(curr->data, start->data);
            pivotPrev = curr;
            curr = curr->next;
        }
        start = start->next;
    }
    swap(curr->data, end->data);
    return pivotPrev;
}

void TicketList::quickSortHelper(Node *start, Node *end)
{
    if (!start || start == end || start == end->next)
        return;

    Node *pivotPrev = partition(start, end);
    quickSortHelper(start, pivotPrev);

    if (pivotPrev && pivotPrev == start)
    {
        quickSortHelper(pivotPrev->next, end);
    }
    else if (pivotPrev && pivotPrev->next)
    {
        quickSortHelper(pivotPrev->next->next, end);
    }
}

void TicketList::quickSort()
{
    quickSortHelper(head, tail);
}

Node *TicketList::partitionByPriority(Node *start, Node *end)
{
    int pivot = end->data->Priority;
    Node *pivotPrev = start;
    Node *curr = start;

    while (start != end)
    {
        if (start->data->Priority < pivot)
        {
            swap(curr->data, start->data);
            pivotPrev = curr;
            curr = curr->next;
        }
        start = start->next;
    }
    swap(curr->data, end->data);
    return pivotPrev;
}

void TicketList::quickSortByPriorityHelper(Node *start, Node *end)
{
    if (!start || start == end || start == end->next)
        return;

    Node *pivotPrev = partitionByPriority(start, end);
    quickSortByPriorityHelper(start, pivotPrev);

    if (pivotPrev && pivotPrev == start)
    {
        quickSortByPriorityHelper(pivotPrev->next, end);
    }
    else if (pivotPrev && pivotPrev->next)
    {
        quickSortByPriorityHelper(pivotPrev->next->next, end);
    }
}

void TicketList::quickSortByPriority()
{
    quickSortByPriorityHelper(head, tail);
}

int TicketList::id = 0;