#include "Agent.cpp"
#include "Ticket.cpp"
#include "TicketList.cpp"
#include "TicketStack.cpp"

class OneStop {
private:
    Agent *agentArray;
    int ticketQueueSize;
    TicketList *ticketQueue;
    TicketStack *closedTickets;

public:
    OneStop();
    void addAgents();
    void assignTicketToAgent();
    void displayMenu();
    void AddTicket();
    void sortAgents();
    void printOpenedTickets();
    void printClosedTickets();
    void closeTicket(int id);
    void removeTicketFromAgent(int id);
    void displayDefaultAlgo();
    void StartSystem();
};
