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
    this->status = true;
    this->closeTime = "";
}
Ticket::Ticket(int ticketID, string customerName, int Priority,
               string serviceRequestDescription,
               string creationTime, string closeTime)
{
    this->ticketID = ticketID;
    this->customerName = customerName;
    this->serviceRequestDescription = serviceRequestDescription;
    this->creationTime = creationTime;
    this->Priority = Priority;
    this->status = true;
    this->closeTime = closeTime;
}
string Ticket::GetCreationTime()
{
    return creationTime;
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

void Ticket::closeTicket(string endingTime)
{
    this->closeTime = endingTime;
    status = false;
};
int Ticket::idGenerator = 2300;

string Ticket::GetserviceRequestDescription()
{
    return serviceRequestDescription;
}

void Ticket::displayTicketDetail()
{
    cout << "Ticket ID: " << this->ticketID << endl;
    cout << "Customer Name: " << this->customerName << endl;
    cout << "Service Request Description: " << this->serviceRequestDescription << endl;
    cout << "Creation Time: " << this->creationTime << endl;
    cout << "Priority: " << this->Priority << endl;
    cout << "Status: " << (this->status ? "Open" : "Closed") << endl;
}