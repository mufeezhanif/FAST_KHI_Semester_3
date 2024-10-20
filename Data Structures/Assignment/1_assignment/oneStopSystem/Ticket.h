#include <bits/stdc++.h>

using namespace std;

class Ticket
{
private:
    string customerName;
    int Priority;
    string serviceRequestDescription;
    string creationTime;
    string closeTime;
    bool status;
    int ticketID;

public:
    Ticket();
    int static idGenerator;
    Ticket(int ticketID, string customerName, int Priority,
           string serviceRequestDescription,
           string creationTime);
    int GetPriority();
    void SetPriority(int Priority);
    string GetCustomerName();
    void SetCustomerName(string customerName);
    void SetserviceRequestDescription(string description);
    int GetTicketID();
    void SetTicketID(int ticketID);
};
