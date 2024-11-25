#include "Agent.h"

Agent::Agent(int agentId, string agentName)
{
    this->agentId = agentId;
    this->agentName = agentName;
    availability = true;
    ticketsAssigned = 0;
}

string Agent::GetAgentName() const
{
    return agentName;
}

void Agent::SetAgentName(string agentName)
{
    agentName = agentName;
}
bool Agent::GetAvailability() const
{
    return availability;
}

void Agent::SetAvailability(bool availability)
{
    this->availability = availability;
}

int Agent::GetAgentId() const
{
    return agentId;
}

void Agent::SetAgentId(int agentId)
{
    agentId = agentId;
}
int Agent::GetTicketsAssigned() const
{
    return ticketsAssigned;
}

void Agent::assignTicketToAgent(int id, string name, int priority, string desc, string crTime)
{
    if (!Agent::GetAvailability())
    {
        cout << "Maximum number of tickets reached" << endl;
        return;
    }
    Ticket *temp = new Ticket(id, name, priority, desc, crTime);
    tickets[ticketsAssigned] =  *temp;
    ticketsAssigned++;
    if (ticketsAssigned == 4)
        Agent::SetAvailability(false);
}

void Agent::SetTicketsAssigned(int ticketsAssigned)
{
    this->ticketsAssigned = ticketsAssigned;
}

int Agent::idGenerator = 1000;
