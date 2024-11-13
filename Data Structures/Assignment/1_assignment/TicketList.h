
#include "Ticket.h"

using namespace std;

class Node {
public:
    Ticket *data;
    Node *next;
    Node(int ticketID, string customerName, int Priority, string serviceRequestDescription, string creationTime);
};

class TicketList {
public:
    Node *head;
    Node *tail;
    int size;
    static int id;
    string sortType;

    TicketList();
    string getCurrentTime();
    void addATicket(int ticketID, string customerName, int Priority, string serviceRequestDescription);
    void sortTickets();
    void removeTicketThroughId(int ticketId);
    Ticket *front();
    Ticket *peek();
    Ticket *Rear();
    Ticket *searchTicketWithId(int ticketID);
    Ticket *searchTicketWithName(string customerName);

    void bubble_sort();
    void selection_sort();
    void insertion_sort();
    void mergeSort();
    void quickSort();
    void quickSortByPriority();

private:
    Node *split(Node *mover);
    Node *merge(Node *first, Node *second);
    Node *MergeSort(Node *mover);
    Node *partition(Node *start, Node *end);
    void quickSortHelper(Node *start, Node *end);
    Node *partitionByPriority(Node *start, Node *end);
    void quickSortByPriorityHelper(Node *start, Node *end);
};
