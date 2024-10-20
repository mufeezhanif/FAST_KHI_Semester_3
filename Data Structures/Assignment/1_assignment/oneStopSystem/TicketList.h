#include "Ticket.cpp"

class Node
{
public:
    Ticket data;

    Node *next;
    Node(int ticketID, string customerName, int Priority, string serviceRequestDescription, string creationTime)
    {
        next = nullptr;
        data = Ticket(ticketID, customerName, Priority, serviceRequestDescription, creationTime);
    }
};

class TicketList
{
public:
    Node *head;
    Node *tail;
    int size;
    TicketList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addATicket(int ticketID, string customerName, int Priority, string serviceRequestDescription, string creationTime)
    {
        if (!head)
        {
            head = new Node(ticketID, customerName, Priority, serviceRequestDescription, creationTime);
            tail = head;
            ++size;
        }
        else
        {
            tail->next = new Node(ticketID, customerName, Priority, serviceRequestDescription, creationTime);
            tail = tail->next;
            ++size;
        }
    }
    void removeTicket(int ticketId)
    {

        if (!head)
        {
            cout << "No Tickets available" << endl;
        }
    }
    void insetionSort()
    {
        if (!head || !head->next)
            return;
        Node *sorted = nullptr;
        Node *current = head;
        while (current != NULL)
        {
            Node *next = current->next;
            if (!sorted || sorted->data- >= current->data)
        }
    }
};
