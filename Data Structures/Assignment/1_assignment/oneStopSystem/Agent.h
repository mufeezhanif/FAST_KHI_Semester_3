#include <bits/stdc++.h>
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
    int *tickets;
    bool availability;
    int ticketsAssigned;


public:
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
};