#include <bits/stdc++.h>

using namespace std;

class Ticket
{
private:
    string customerName;
    string serviceRequestDescription;
    string creationTime;
    string closeTime;
    bool status;
    int ticketID;

public:
    int Priority;
    Ticket();
    int static idGenerator;
    Ticket(int ticketID, string customerName, int Priority,
           string serviceRequestDescription,
           string creationTime);
    Ticket(int ticketID, string customerName, int Priority,
           string serviceRequestDescription,
           string creationTime, string closeTime);

    int GetPriority();
    void SetPriority(int Priority);
    string GetCustomerName();
    void SetCustomerName(string customerName);
    void SetserviceRequestDescription(string description);
    string GetserviceRequestDescription();
    int GetTicketID();
    void SetTicketID(int ticketID);
    string GetCreationTime();
    void closeTicket(string endingTime);
    void displayTicketDetail();
    Ticket * operator=( Ticket&other);
};
