#include "Agent.cpp"
#include "Ticket.cpp"
#include "TicketList.cpp"

class OneStop
{
private:
    Agent *agentArray;
    int size;
    OneStop()
    {
        agentArray = nullptr;
        size = 0;
    }

    void addAnAgent()
    {
        string name;
        cout << "Enter Agent Name:\n ";
        getline(cin, name);
        Agent::idGenerator += 1;
        int id = Agent::idGenerator;
        if (size == 0)
        {
            agentArray = new Agent(id, name);
            cout << "New Agent Added Successfully" << endl;
            ++size;
        }
        else
        {
            Agent *temp = new Agent[size + 1];
            for (int i = 0; i < size; ++i)
            {
                temp[i] = agentArray[i];
            }
            temp[size] = Agent(id, name);
            delete agentArray;
            ++size;
            agentArray = new Agent[size+1];
            for(int i=0;i<size;++i){
                agentArray[i] = temp[i];
            }
            delete temp;
        }
    }
    void assignTicket()
    {
        
    }
};