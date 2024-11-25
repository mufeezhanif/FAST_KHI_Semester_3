#include <bits/stdc++.h>

#include "TicketList.h"
using namespace std;

// Each support agent will have the following attributes:
// Agent ID (int)
// Name (String)
// Assigned Tickets (List of Ticket IDs)
// Availability (boolean)

class Agent
{
private:
    int agentId;
    string agentName;
    bool availability;
    int ticketsAssigned;

public:
    Ticket *tickets = new Ticket[5];
    Agent();
    static int idGenerator;
    Agent(int agentId, string agentName);
    string GetAgentName() const;
    void SetAgentName(string agentName);
    bool GetAvailability() const;
    void SetAvailability(bool availability);
    int GetAgentId() const;
    void SetAgentId(int agentId);
    int GetTicketsAssigned() const;
    void SetTicketsAssigned(int ticketsAssigned);
    void assignTicketToAgent(int id,string name, int priority ,string  desc, string crTime);
};