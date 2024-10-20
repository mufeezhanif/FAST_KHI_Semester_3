#include "Ticket.h"

Ticket::Ticket(int ticketID, string customerName, int Priority,
               string serviceRequestDescription,
               string creationTime)
{
    this->ticketID = ticketID;
    this->customerName = customerName;
    this->serviceRequestDescription = serviceRequestDescription;
    this->creationTime = creationTime;
    this->Priority = Priority;
    this->status= true;
    this->closeTime = "";
}

int Ticket::GetPriority()
{
    return Priority;
}

void Ticket::SetPriority(int Priority)
{
    this->Priority = Priority;
}

string Ticket::GetCustomerName()
{
    return customerName;
}

void Ticket::SetCustomerName(string customerName)
{
    this->customerName = customerName;
}
int Ticket::GetTicketID()
{
    return ticketID;
}

void Ticket::SetTicketID(int ticketID)
{
    this->ticketID = ticketID;
}

int Ticket::idGenerator = 2300;