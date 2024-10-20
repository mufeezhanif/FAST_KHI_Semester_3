#include "Ticket.cpp"

class Node
{
private:
    Ticket data;
    Node *next;

public:
    Node(Ticket ticket)
    {
        next = nullptr;
        data = ticket;
    }
    
};
