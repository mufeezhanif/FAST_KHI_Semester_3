#include "Ticket.h"

class NodeStack
{
public:
    Ticket *data;
    NodeStack *next;

    NodeStack(int ticketID, string customerName, int Priority, string serviceRequestDescription, string creationTime, string closeTime);
};

class TicketStack
{
public:
    NodeStack *start;
    NodeStack *end;
    int size;

    TicketStack();

    void push(int id, string name, int priority, string desc, string crTime, string clTime);
    Ticket *pop();
    Ticket *top();
};