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
    availability = availability;
}

int Agent::GetAgentId() const
{
    return agentId;
}

void Agent::SetAgentId(int agentId)
{
    agentId = agentId;
}
int Agent::GetTicketsAssigned() const {
    return ticketsAssigned;
}
void Agent::SetTicketsAssigned(int ticketsAssigned) {
    this->ticketsAssigned = ticketsAssigned;
}

int Agent::idGenerator = 1000;