#include "TicketStack.h"

NodeStack::NodeStack(int ticketID, std::string customerName, int Priority, std::string serviceRequestDescription, std::string creationTime, std::string closeTime)
{
    next = nullptr;
    data = new Ticket(ticketID, customerName, Priority, serviceRequestDescription, creationTime, closeTime);
}

TicketStack::TicketStack()
{
    size = 0;
    start = nullptr;
    end = nullptr;
}

void TicketStack::push(int id, std::string name, int priority, std::string desc, std::string crTime, std::string clTime)
{
    if (!start)
    {
        start = new NodeStack(id, name, priority, desc, crTime, clTime);
        end = start;
        ++size;
        return;
    }
    end->next = new NodeStack(id, name, priority, desc, crTime, clTime);
    end = end->next;
    ++size;
}

Ticket *TicketStack::pop()
{
    if (!start)
    {
        return nullptr;
    }
    Ticket *temp = start->data;
    NodeStack *nodeToDelete = start;
    start = start->next;
    delete nodeToDelete;
    --size;
    return temp;
}

Ticket *TicketStack::top()
{
    if (!start)
    {
        return nullptr;
    }
    return start->data;
}
