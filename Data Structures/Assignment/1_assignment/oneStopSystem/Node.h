#include "Ticket.h"

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
