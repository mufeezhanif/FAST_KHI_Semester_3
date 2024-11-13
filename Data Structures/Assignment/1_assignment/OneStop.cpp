#include "OneStop.h"

OneStop::OneStop()
{
    agentArray = nullptr;
    ticketQueueSize = 0;
    ticketQueue = new TicketList();
    closedTickets = new TicketStack();
}

void OneStop::addAgents()
{
    ifstream agentFile("agents.txt");
    if (!agentFile)
    {
        cout << "Please create an agents.txt file containing the name of 6 agents for the system. The file must be in the current directory. After creating, restart the program." << endl;
        exit(0);
    }
    int j = 1;
    string temp;
    while (getline(agentFile, temp))
    {
        ++j;
    }
    if (j != 6)
    {
        cout << "Please create an agents.txt file containing the name of 6 agents for the system. The file must be in the current directory. After creating, restart the program." << endl;
        exit(0);
    }
    agentFile.clear();
    agentFile.seekg(0, ios::beg);

    agentArray = new Agent[6];
    int i = 0;
    string name;
    while (getline(agentFile, name))
    {
        Agent::idGenerator += 1;
        int id = Agent::idGenerator;
        agentArray[i++] = Agent(id, name);
    }
}

void OneStop::assignTicketToAgent()
{
    sortAgents();
    Ticket *ticket = ticketQueue->front();
    int i = 0;

    int id = ticket->GetTicketID();
    string name = ticket->GetCustomerName();
    string desc = ticket->GetserviceRequestDescription();
    string crTime = ticket->GetCreationTime();
    int priority = ticket->GetPriority();

    while (i < 6)
    {
        if (agentArray[i].GetAvailability())
        {
            agentArray[i].assignTicketToAgent(id, name, priority, desc, crTime);
            break;
        }
        ++i;
    }
}

void OneStop::displayMenu()
{
    cout << "\n===================================================" << endl;
    cout << "             Ticket Management System              " << endl;
    cout << "===================================================" << endl;
    cout << setw(5) << " " << "1. Add Ticket" << endl;
    cout << setw(5) << " " << "2. Assign Ticket" << endl;
    cout << setw(5) << " " << "3. Show Opened Tickets" << endl;
    cout << setw(5) << " " << "4. Show Closed Tickets" << endl;
    cout << setw(5) << " " << "5. Close Ticket" << endl;
    cout << setw(5) << " " << "6. Show Default Sorting Algorithms" << endl;
    cout << setw(5) << " " << "7. End Program" << endl;
    cout << "===================================================" << endl;
}

void OneStop::AddTicket()
{
    string name, desc;
    cout << "Enter your name: " << endl;
    getline(cin >> ws, name);
    cout << "Enter Description: " << endl;
    getline(cin >> ws, desc);
    cout << "Enter Priority: " << endl;
    int pr;
    cin >> pr;
    TicketList::id++;
    int id = TicketList::id;
    ticketQueue->addATicket(id, name, pr, desc);
    ++ticketQueueSize;
}

void OneStop::sortAgents()
{
    bool swapped;
    for (int i = 0; i < 6; ++i)
    {
        swapped = false;
        for (int j = 0; j < 6 - i - 1; ++j)
        {
            if (agentArray[j + 1].GetTicketsAssigned() > agentArray[j].GetTicketsAssigned())
            {
                swap(agentArray[j], agentArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void OneStop::printOpenedTickets()
{
    Node *temp = ticketQueue->head;
    while (temp)
    {
        temp->data->displayTicketDetail();
        temp = temp->next;
    }
}

void OneStop::printClosedTickets()
{
    NodeStack *temp = closedTickets->start;
    while (temp)
    {
        temp->data->displayTicketDetail();
        temp = temp->next;
    }
}

void OneStop::closeTicket(int id)
{
    Node *temp = ticketQueue->head;

    if (temp->data->GetTicketID() == id)
    {
        int id = temp->data->GetTicketID();
        string name = temp->data->GetCustomerName();
        string desc = temp->data->GetserviceRequestDescription();
        string crTime = temp->data->GetCreationTime();
        string clTime = ticketQueue->getCurrentTime();
        int priority = temp->data->GetPriority();
        closedTickets->push(id, name, priority, desc, crTime, clTime);
        ticketQueue->head = temp->next;
        delete temp;
    }
    else
    {
        while (temp->next)
        {
            if (temp->next->data->GetTicketID() == id)
            {
                Node *toDelete = temp->next;
                int id = toDelete->data->GetTicketID();
                string name = toDelete->data->GetCustomerName();
                string desc = toDelete->data->GetserviceRequestDescription();
                string crTime = toDelete->data->GetCreationTime();
                int priority = toDelete->data->GetPriority();
                string clTime = ticketQueue->getCurrentTime();
                closedTickets->push(id, name, priority, desc, crTime, clTime);
                temp->next = toDelete->next;
                delete toDelete;
                break;
            }
            temp = temp->next;
        }
    }
    removeTicketFromAgent(id);
}

void OneStop::removeTicketFromAgent(int id)
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (agentArray[i].tickets[j].GetTicketID() == id)
            {
                for (int k = j; k < 4; ++k)
                {
                    agentArray[i].tickets[k] = agentArray[i].tickets[k + 1];
                }
                return;
            }
        }
    }
    cout << "No ticket found with the given id" << endl;
}

void OneStop::displayDefaultAlgo()
{
    ifstream configFile("config.txt");
    if (!configFile)
    {
        cout << "Can't open config.txt, please create or move the file in current location" << endl;
    }
    else
    {
        string sortType;
        getline(configFile, sortType);
        cout << sortType << endl;
    }
}

void OneStop::StartSystem()
{
    addAgents();
    int choice;
    int end = -1;
    while (end != 0)
    {
        displayMenu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cout << "\n---------------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
            cout << ">>> [Adding a ticket...]" << endl;
            AddTicket();
            break;
        case 2:
            cout << ">>> [Assigning a ticket...]" << endl;
            assignTicketToAgent();
            break;
        case 3:
            cout << ">>> [Showing opened tickets...]" << endl;
            printOpenedTickets();
            break;
        case 4:
            cout << ">>> [Showing closed tickets...]" << endl;
            printClosedTickets();
            break;
        case 5:
            int id;
            cout << "Enter ID of ticket you want to close: ";
            cin >> id;
            closeTicket(id);
            break;
        case 6:
            displayDefaultAlgo();
            break;
        case 7:
            cout << ">>> [Ending program...]" << endl;
            end = 0;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        cout << "\n---------------------------------------------------" << endl;
    }
}
